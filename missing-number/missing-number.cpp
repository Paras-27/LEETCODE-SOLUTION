class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int sum_without_n=0;
        for(int i=0;i<n;i++){
            sum_without_n+=nums[i];
        }
        return sum-sum_without_n;
    }
};