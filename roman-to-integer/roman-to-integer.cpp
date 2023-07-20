class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int cnt=0,i;
        for(i=s.size()-1;i>0;i--){
            if(s[i]=='V' && s[i-1]=='I'){
                cnt+=4;
                i--;
            }
            else if(s[i]=='X' && s[i-1]=='I'){
                cnt+=9;
                i--;
            }
            else if(s[i]=='L' && s[i-1]=='X'){
                cnt+=40;
                i--;
            }
            else if(s[i]=='C' && s[i-1]=='X'){
                cnt+=90;
                i--;
            }
            else if(s[i]=='D' && s[i-1]=='C'){
                cnt+=400;
                i--;
            }
            else if(s[i]=='M' && s[i-1]=='C'){
                cnt+=900;
                i--;
            }
            else{
                cnt+=mp[s[i]];
            }
        }
        if(i==0){
            cnt+=mp[s[i]];
        }
        return cnt;
    }
};