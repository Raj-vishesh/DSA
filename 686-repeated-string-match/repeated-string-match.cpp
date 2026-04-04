class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int cnt = 1;
        while(temp.length() < b.length()){
            temp+= a;
            cnt++;
        }

        if(temp.find(b) !=  string:: npos){
            return cnt;
        }

        temp+= a;
        if(temp.find(b) != string :: npos){
            return cnt+1;
        }


        return -1;
    }
};