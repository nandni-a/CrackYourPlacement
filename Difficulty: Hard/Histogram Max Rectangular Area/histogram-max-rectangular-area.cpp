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
};
