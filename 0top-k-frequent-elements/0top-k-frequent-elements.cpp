class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans(k);
        priority_queue<pair<int,int>>pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        for(int i=0;i<k;i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};