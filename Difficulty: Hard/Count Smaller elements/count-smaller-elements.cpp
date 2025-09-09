// User function Template for C++
//  User function template for C++

class Solution {
  public:
    void merge(int l,int mid,int r,vector<pair<int,int>>&arr,vector<int>&res){
        int i=l;
        int j=mid+1;
        vector<pair<int,int>> temp;
        int rightCount = 0;
        while(i<=mid && j<=r){
            if(arr[i].first <= arr[j].first){
                res[arr[i].second]+=rightCount;
                temp.push_back(arr[i]);
                i++;
            }
            else{
                rightCount++;
                temp.push_back(arr[j]);
                j++;
                
            }
        }
        while(i<=mid){
            res[arr[i].second]+=rightCount;
                temp.push_back(arr[i]);
                i++;
        }
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k=l;k<=r;k++){
            arr[k]=temp[k-l];
        }
    }
    void mergeSort(int l,int r,vector<pair<int,int>>&arr,vector<int>&res){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(l,mid,arr,res);
        mergeSort(mid+1,r,arr,res);
        merge(l,mid,r,arr,res);
        
    }
    vector<int> constructLowerArray(vector<int> &nums) {
        // code here
        int n=nums.size();
        vector<int>res(n,0);
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergeSort(0,n-1,arr,res);
        return res;
        
    }
};