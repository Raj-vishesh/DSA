class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant;
        queue<int> dire;

        for(int i = 0 ; i < n ; i++){
            if(senate[i] == 'R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }

        while(!radiant.empty() && !dire.empty()){
            int ridx = radiant.front();
            radiant.pop();

            int didx = dire.front();
            dire.pop();

            if(ridx < didx){
                radiant.push(ridx+ n);
            }
            else{
                dire.push(didx+ n);
            }
        }
        if(radiant.empty()){
            return "Dire";
        }
        else return "Radiant";
    }
};