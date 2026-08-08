class Solution {
public:
    void merge(vector<int>& nums, int s, int m, int e){
        int n1=m-s+1, n2=e-m;
        vector<int>left(n1), right(n2);
        for(int i=0; i<n1; i++) left[i]=nums[s+i];
        for(int j=0; j<n2; j++) right[j]=nums[m+1+j];
        int i=0, j=0, k=s;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
            }else{
                nums[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e) return;
        else{
            int m=s+(e-s)/2;
            mergeSort(nums, s, m);
            mergeSort(nums, m+1, e);
            merge(nums, s, m, e);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};