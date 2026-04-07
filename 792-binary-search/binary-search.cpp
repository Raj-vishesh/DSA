class Solution {
public:
    int search(vector<int>& arr, int target) {
        // int lo = 0, hi = nums.size() -1;
        // while(lo<= hi){
        //     int mid = (lo+hi)/2;
        //     if(nums[mid] == target) return mid;
        //     else if(nums[mid] <target) lo = mid+1;
        //     else  hi = mid-1;
            

        // }
        //  return -1;
        int n = arr.size();
        int lo = 0 , hi = n-1;
        while(lo<=hi){
            int mid = (lo + hi )/ 2;
            if(arr[mid] == target ) return mid;
            else if(arr[mid] < target ) lo = mid+1;
            else hi = mid-1; 
        }
        return -1;
    }
};