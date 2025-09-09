// User function Template for C++
class Solution {
  public:
    long long solve(int X, int Y, string s) {
        // code here
        string first,second;
        int firstVal,secondVal;
        if(X>=Y){
            first="pr";
            second="rp";
            firstVal=X;
            secondVal=Y;
        }
        else{
            first="rp";
            second="pr";
            firstVal=Y;
            secondVal=X;
        }
        long long amount=0;
        stack<char>st;
        for(char ch:s){
            if(!st.empty() && st.top()==first[0] && ch==first[1]){
                st.pop();
                amount+=firstVal;
            }
            else{
                st.push(ch);
            }
        }
        string remain="";
        while(!st.empty()){
            remain+=st.top();
            st.pop();
        }
        reverse(remain.begin(),remain.end());
        st=stack<char>();
        for(char ch:remain){
            if(!st.empty() && st.top()==second[0] && ch==second[1]){
                st.pop();
                amount+=secondVal;
            }
            else{
                st.push(ch);
            }
        }
        return amount;
    }
};