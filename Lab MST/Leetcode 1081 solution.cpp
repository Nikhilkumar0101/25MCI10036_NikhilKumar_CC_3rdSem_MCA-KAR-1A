class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        unordered_map<char,int> last_occur(26);
        vector<bool> present(26,false);
        for(int i=0;i<n;i++){
            last_occur[s[i]]=i;
        }
        string ans;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(present[ch-'a']==true){
                continue;
            }
            while(!ans.empty() && ans.back()>ch && last_occur[ans.back()]>i){
                present[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            present[ch-'a']=true;
        }
        return ans;
    }
};