class Solution {
public:
    int countCommas(int n) {
        int temp = 1000;
        int ans = n - temp +1 ;
        if(ans < 0){
            return 0;
        }
        else return ans;
    }
};