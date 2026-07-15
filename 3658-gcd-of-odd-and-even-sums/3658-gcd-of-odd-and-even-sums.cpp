class Solution {
public:
    int gcd(int oddSum, int evenSum){
        if(oddSum==0) return evenSum;
        return gcd(evenSum%oddSum, oddSum);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum=0, evenSum=0;
        int odd=1, even=2;
        for(int i=0; i<n; i++){
            oddSum+=odd;
            odd+=2;
            evenSum+=even;
            even+=2;
        }
        return gcd(oddSum, evenSum);
    }
};