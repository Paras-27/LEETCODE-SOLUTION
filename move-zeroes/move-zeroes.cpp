class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n=v.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(v[i]!=0){
                v[k++]=v[i];
            }
        }
        for(int i=k;i<n;i++){
            v[i]=0;
        }

    }
};