class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(), sum=nums[0];
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        for(int i=1; i<n; i++){
            if(nums[i-1]+1==nums[i]) sum+=nums[i];
            else break;
        }
        while(s.count(sum)){
            sum++;
        }
        return sum;
    }
};