
bool metaStrings(string s1, string s2) {
    // your code here
    vector<int>diff;
    int n=s1.length();
    int m=s2.length();
    if(n!=m) return false;
    if(s1==s2) return false;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            diff.push_back(i);
            if(diff.size()>2) return false;
        }
    }
    if(diff.size()!=2) return false;
    int x=diff[0];
    int y=diff[1];
    return (s1[x]==s2[y] && s1[y]==s2[x]);
}