class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        vector<int> pref(n);
        pref[0]=nums[0];
        int sum=0;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        // cout<<0;
        int ans=n+1;
        if(n-1>0 && pref[n-2]==0){
            ans=n-1;
        }
        for(int i=n-1;i>0;i--){
            // cout<<i<<" ";
            sum+=nums[i];
            if(i==1 && sum==0){
                ans=0;
            }
            else if(i>1 && sum==pref[i-2]){
                ans=i-1;
            }
        }
        // cout<<"\n";
        return ans==n+1 ?-1 : ans;
    }
};