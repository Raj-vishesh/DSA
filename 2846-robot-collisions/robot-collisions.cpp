class Solution {
    struct Robot {
        int pos;
        int health;
        char dir;
        int id;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        
        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        vector<Robot> st;
        
        for (auto& robot : robots) {
            if (robot.dir == 'R') {
                st.push_back(robot);
            } else {
                while (!st.empty() && st.back().dir == 'R' && robot.health > 0) {
                    if (st.back().health == robot.health) {
                        st.pop_back();
                        robot.health = 0;
                    } else if (st.back().health > robot.health) {
                        st.back().health -= 1;
                        robot.health = 0;
                    } else {
                        st.pop_back();
                        robot.health -= 1;
                    }
                }
                if (robot.health > 0) {
                    st.push_back(robot);
                }
            }
        }

        sort(st.begin(), st.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> result;
        for (const auto& robot : st) {
            result.push_back(robot.health);
        }

        return result;
    }
};