// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size()==0) return "";
        if(arr.size()==1) return arr[0];
        string str=arr[0];
        int len=str.length();
        for(int i=1;i<arr.size();i++){
            if(arr[i].length()>len){
                str=arr[i];
                len=arr[i].length();
            }
        }
        for(int i=0;i<arr.size();i++){
            int j=0;
            for(;j<len;j++){
                if(arr[i][j]!=str[j]){
                    break;
                }
            }
            str=str.substr(0,j);
            if(str.empty()) break;
        }
        return str;
        
    }
};