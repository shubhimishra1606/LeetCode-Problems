class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
     int count=0, n=nums.size();
     if(n<=2) return n;
     for(int i: nums){
        count|=i;
     }
     return count+1;
    }
};