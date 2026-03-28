class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto &s : tokens){

            if(s == "+" || s == "-" || s== "*" || s == "/" ){
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();

                if(s == "+") st.push(a+b);
                else if(s == "*") st.push(a*b);
                else if(s == "-") st.push(a-b);
                else st.push(a/b);
                
            }
            else{
                st.push(stoi(s));
            }
        }

        return (int)st.top();

    }
};