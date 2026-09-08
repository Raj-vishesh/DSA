class Solution {
public:
    int countCommas(int n) {
        int total_commas  = 0;

        if(n >= 1000){
            total_commas += n- 1000 + 1;
        }

        if(n >= 10000000){
            total_commas += n- 10000000 + 1;
        }

        return total_commas;
    }
};