class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {//left=-1, right=-1, 
        int low=0, high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high) {
            if(nums[mid]==target) {
                break;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        if(low>high) {
            return {-1, -1};
        } else {//找边界
            while(nums[low]!=target) {
                low++;
            }
            while(nums[high]!=target) {
                high--;
            }
            return {low, high};
        }
    }
};
