class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ch(n,0);
        for(int i=0;i<n;i++){
            ch[i]=nums[nums[i]];
        }
        return ch;
    }
};