class Solution {
public:
    bool judgeSquareSum(int c) {
        long long  lo = 0 ; long long  hi = sqrt(c);
        while(lo <= hi){
            long long  curr_sum = lo * lo + hi * hi;
            if(curr_sum == c) return true;
            else if(curr_sum < c){
                lo++;
            }
            else{
                hi--;
            }
        }

        return false;
    }
};