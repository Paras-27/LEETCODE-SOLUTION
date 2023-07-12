class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=0;
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                ind=i;
            }
            maxi=max(maxi,nums[i]);
        }
        for(int i:nums){
            if(i!=maxi && i*2>maxi){
                return -1;
            }
        }
        return ind;
    }
};