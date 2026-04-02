class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n = nums1.size();
        priority_queue<pair<int, pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;


        if(nums1.empty() || nums2.empty() || k == 0) return result;

        for(int i = 0 ; i < min(n ,k) ; i++){
            int sum = nums1[i] + nums2[0];
            pq.push({sum , {i , 0}});
        }

        while(!pq.empty() && k >0){
            auto current = pq.top();
            pq.pop();

            int i = current.second.first;
            int j = current.second.second;

            result.push_back({nums1[i] , nums2[j]});
            k--;

            if(j+1 < nums2.size()){
                int neextsum = nums1[i] + nums2[j+1];
                pq.push({neextsum ,{i,j+1}});
            }
        }

        return result;

   
    }
};