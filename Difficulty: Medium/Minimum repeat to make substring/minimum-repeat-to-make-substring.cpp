class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        vector<int>freq(26,0);
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            if(freq[s2[i]-'a']==0){
                return -1;
            }
        }
        string temp=s1;
        int ans=1;
        while(temp.length()<s2.length()){
            temp+=s1;
            ans++;
        }
        if(temp.find(s2)!=-1){
            return ans;
        }
        temp+=s1;
        ans++;
        if(temp.find(s2)!=-1){
            return ans;
        }
        return -1;
        
    }
};