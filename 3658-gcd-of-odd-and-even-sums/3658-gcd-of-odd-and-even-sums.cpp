class Solution {
public:
    int gcdOfOddEvenSums(int n) {
    int evenSum=0,oddSum=0;
    for(int i=1;i<=n;i++)
    {
      oddSum+=(2*i-1);
      evenSum+=2*i;
    } 
    return std::gcd(oddSum,evenSum);  
    }
};