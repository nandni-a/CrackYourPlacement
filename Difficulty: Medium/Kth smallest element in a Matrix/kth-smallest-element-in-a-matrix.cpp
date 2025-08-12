class Solution {
public:
    int find(int x,vector<vector<int>> &mat){
        int n=mat.size();
        int cnt=0;
        for(auto & row:mat){
            cnt+= upper_bound(row.begin(),row.end(),x)-row.begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int l=mat[0][0];
        int r=mat[n-1][n-1];
        while(l<r){
            int mid=l+ (r-l)/2;
            if(find(mid,mat)>=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
