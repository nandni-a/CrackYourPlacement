class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size();i+=2){
            if(i+1< arr.size())
                swap(arr[i],arr[i+1]);
        }
    }
};