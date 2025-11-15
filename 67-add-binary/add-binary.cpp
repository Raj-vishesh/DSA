class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry) {
            int ones = carry;

            if(i >= 0) ones += (a[i--] == '1');
            if(j >= 0) ones += (b[j--] == '1');

            ans.push_back((ones % 2) + '0');  
            carry = (ones >= 2);              
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
