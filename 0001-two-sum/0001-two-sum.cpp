class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(mp.find(x)!=mp.end()){
                v.push_back(i);
                v.push_back(mp[x]);
                break;
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};