class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(), nums.end());
        int mid=nums[(nums.size()-1)/2];
        for(int i=0; i<nums.size(); i++){
            sum+=abs(nums[i]-mid);
        }
        return sum;
    }
};