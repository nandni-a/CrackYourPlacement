class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>mapp={{'I',1}
        ,{'V',5},{'L',50},{'X',10},{'C',100},{'D',500},{'M',1000}};
        
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int curr=mapp[s[i]];
            int next=0;
            if(i<n-1) next=mapp[s[i+1]];
            if(curr<next){
                ans-=curr;
            }
            else{
                ans+=curr;
            }
        }
        return ans;
        
    }
};