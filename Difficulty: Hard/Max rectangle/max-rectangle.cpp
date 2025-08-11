class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<int>st;
        int maxArea=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse= st.empty() ? -1: st.top();
                int area= arr[el]* (nse-pse-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int el=st.top(); st.pop();
            int pse= st.empty()? -1:st.top();
            int area= arr[el]* (nse-pse-1);
            maxArea=max(maxArea,area);
            
        }
        return maxArea;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>pre(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+= mat[i][j];
                if(mat[i][j]==0) sum=0;
                pre[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<m;i++){
            maxArea=max(maxArea,getMaxArea(pre[i]));
        }
        return maxArea;
    }
};