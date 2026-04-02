class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long  n = target.size();
        if(n == 1) return target[0] == 1;
        priority_queue<long long > pq;
        long long  tot_sum = 0;
        for(int i = 0 ; i < n ; i++){
            tot_sum += target[i];
            pq.push(target[i]);
        }

        while(pq.top() >1){
            auto max_ele = pq.top();
            pq.pop();

            long long rem_sum = tot_sum  - max_ele;

            if(rem_sum == 1) return true;

            if(rem_sum ==0 || max_ele <= rem_sum){
                return false;
            }

            long long newval = max_ele % rem_sum;


            if(newval == 0) return false;
            pq.push(newval);
            tot_sum = rem_sum + newval;
        }
        
        return true;
 
    }
};