class Solution {
  public:
    string add(string &first,string &second){
        string res;
        int carry=0;
        int len1=first.length();
        int len2=second.length();
        int i=len1-1;
        int j=len2-1;
        while(i>=0 || j>=0 || carry>0){
            int dig1= i>=0 ? first[i--]-'0' :0;
            int dig2= j>=0 ? second[j--]-'0' :0;
            int sum=dig1+dig2+carry;
            carry=sum/10;
            res.push_back((sum%10)+'0');
            
        }
        reverse(res.begin(),res.end());
         int x=0;
        while(x<res.size() && res.at(x)=='0') {
            x++;
        }
        string ans=res.substr(x,res.size()-x+1);
        return ans;
    }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0;
        string first="";
        string second="";
        int n=arr.size();
        while(i<n){
            string temp=to_string(arr[i]);
            if(i%2==0){
                first+=temp;
            }
            else{
                second+=temp;
            }
            i++;
        }
        return add(first,second);
    }
};