class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Agar intervals khali hai toh empty vector return kardo
        if(intervals.empty()) return {};
        
        // STEP 1: Sort the intervals based on starting time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        // STEP 2: Pehla interval answer mein daal do
        ans.push_back(intervals[0]);
        
        // STEP 3: Baaki intervals ko check karo
        for(int i = 1; i < intervals.size(); i++) {
            
            // ans.back() hume answer vector ka aakhri interval deta hai
            // intervals[i][0] current interval ka START time hai
            // ans.back()[1] pichle interval ka END time hai
            
            if(ans.back()[1] >= intervals[i][0]) {
                // OVERLAP HO RAHA HAI
                // End time ko update karo dono mein se maximum le kar
                // (Max isliye lete hain kyunki case aisa bhi ho sakta hai: [1,4] and [2,3] -> merge hoke [1,4] hi rahega)
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } 
            else {
                // OVERLAP NAHI HO RAHA
                // Seedha naye interval ko answer mein push kar do
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};