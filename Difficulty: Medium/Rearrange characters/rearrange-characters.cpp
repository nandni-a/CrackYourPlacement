class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        int hash[26]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        int freq=0;
        char alpha;
        for(int i=0;i<26;i++){
            if(hash[i]>freq){
                freq=hash[i];
                alpha=i+'a';
            }
        }
        if(freq>(s.length()+1)/2) return "";
        int ind=0;
        while(freq!=0){
            s[ind]=alpha;
            freq--;
            ind+=2;
        }
        hash[alpha-'a']=0;
        for(int i=0;i<26;i++){
            while(hash[i]>0){
                ind=ind<s.length()? ind:1;
                s[ind]=i+'a';
                ind+=2;
                hash[i]--;
            }
        }
        return s;
    }
};