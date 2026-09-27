class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";

        for(char c : s){
            if(c == '('){
                st.push(ans.length());
            }
            else if(c == ')'){
                int j = st.top();
                st.pop();
                reverse(ans.begin() + j , ans.end());
            }

            else{
                ans.push_back(c);
            }
        }

        return ans;
    }
};