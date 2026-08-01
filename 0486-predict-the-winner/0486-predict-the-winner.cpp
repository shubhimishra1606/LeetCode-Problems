class Solution {
public:
    int solve(vector<int>& nums, int st, int end){
        if(st==end) return nums[st];
        int pickLeft=nums[st]-solve(nums,st+1,end);
        int pickRight=nums[end]-solve(nums,st,end-1);
        return max(pickLeft,pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int st=0, end=nums.size()-1;
        return solve(nums,st,end)>=0;
    }
};