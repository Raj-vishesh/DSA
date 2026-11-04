class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // two halves oto maintain the median 

        multiset<long long> lower , upper;
        long long lower_sum = 0 , upper_sum = 0;

        auto balance = [&]() {
            while( lower.size() > upper.size()+1) {
                long long val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                lower_sum -= val;
                upper.insert(val);
                upper_sum += val;
            }

            while(lower.size() < upper.size()){
                long long val = *upper.begin();
                upper.erase(upper.begin());
                upper_sum -= val;
                lower.insert(val);
                lower_sum += val;               
            } 
        };

        auto add = [&] (long long val){

            if(lower.empty() || val <= *lower.rbegin()) {
                lower.insert(val);
                lower_sum += val;
            }
            else{
                upper.insert(val);
                upper_sum += val;
            }
            balance();

        };

        auto remove =[&] (long long val) {

            auto it = lower.find(val);
            if(it!= lower.end()){
                lower.erase(it);
                lower_sum -= val;
            }
            else{
                upper.erase(upper.find(val));
                upper_sum -= val;
            }
            balance();
        };

        // now calculate the minimum cost for rvey window

        vector<long long> cost;

        for(int i = 0 ; i < n ; i++){
            add(nums[i]);

            if(i >= x) {
                remove(nums[i-x]);
            }

            if(i >= x-1) {
                long long median = *lower.rbegin();
                long long operations = median * lower.size() - lower_sum + upper_sum - median * upper.size();

                cost.push_back(operations);
            }
        }

        //  now use the dp for minimum cost of each window 

        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dp(k+1 , vector<long long>(n+1 ,INF) );

        for(int i = 0 ; i <= n ; i++){

            dp[0][i] = 0;

        }

        for(int t = 1 ; t <= k; t++){
            for(int i = 1 ; i <= n ; i++){

                dp[t][i] = dp[t][i-1];

                if(i >= x){
                    dp[t][i] = min(dp[t][i] , dp[t-1][i-x] + cost[i-x]);
                }
            }
        }

        return dp[k][n];


    }
};