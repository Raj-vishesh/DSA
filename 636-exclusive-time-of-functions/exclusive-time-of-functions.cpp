class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> result(n, 0);
        int prevtime = 0;

        for(auto& s : logs){
            int firstcol = s.find(':');
            int lastcol = s.find_last_of(':');

            int id = stoi(s.substr( 0 , firstcol));
            string type = s.substr(firstcol + 1 , lastcol - firstcol -1 );
            int timestamp = stoi(s.substr(lastcol + 1));


            if(type == "start"){
                if(!st.empty()){
                    result[st.top()] += timestamp - prevtime;
                }
                st.push(id);
                prevtime = timestamp;
            }

            else{
                result[st.top()] += timestamp - prevtime + 1;
                st.pop();
                prevtime = timestamp +1 ;
            }
            


        }

        return result;



    }
};