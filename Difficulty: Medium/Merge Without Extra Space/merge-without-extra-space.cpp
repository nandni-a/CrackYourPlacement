class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size();
        int m=b.size();
        int l=n-1;
        int r=0;
        while(l>=0 && r<m){
            if(a[l]>b[r]){
                swap(a[l],b[r]);
                l--;
                r++;
            }
            else{
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};