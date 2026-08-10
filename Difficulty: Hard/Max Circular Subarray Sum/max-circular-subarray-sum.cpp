class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int glomax=arr[0];
        int glomin=arr[0];
        int curmax=0;
        int curmin=0;
        int total=0;
        for(int i=0;i<arr.size();i++){
            curmax=max(curmax+arr[i],arr[i]);
            curmin=min(curmin+arr[i],arr[i]);
            glomax=max(glomax,curmax);
            glomin=min(glomin,curmin);
            total+= arr[i];
        }
        if(glomax>0){
            return max(glomax,total-glomin);
        }
        else{
            return glomax;
        }
        
    }
};