class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26,0);
        for(int i=0;i<s.size();i++){
            alphabet[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            alphabet[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(alphabet[i]){
                return false;
            }
        }
        return true;
    }
};