// User function Template for C++
bool dfs(string &cand,int l,unordered_set<string>&seen,int pos=0){
    if(pos==l){
        if(!seen.count(cand)) return true;
        return false;
    }
    for(char ch='a';ch<='z';ch++){
        cand[pos]=ch;
        if(dfs(cand,l,seen,pos+1)) return true;
    }
    return false;
}
string lexicographicalSmallestString(string& s) {
    // Write your code here..
    int n=s.length();
    for(int l=1;l<=3;l++){
        unordered_set<string>seen;
        for(int i=0;i+l<=n;i++){
            seen.insert(s.substr(i,l));
        }
        string candidate(l,'a');
        if(dfs(candidate,l,seen)) return candidate;
    }
    return "";
}
