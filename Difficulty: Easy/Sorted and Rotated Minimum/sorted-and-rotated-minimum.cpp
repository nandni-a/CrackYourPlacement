class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int low=0;
       int high=arr.size()-1;
       int small=INT_MAX;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(arr[mid]<small)
           {
               small=arr[mid];
               if(arr[mid]<arr[high])
               {
                   high=mid-1;
               }
               else
               {
                   low=mid+1;
               }
           }
           else
           {
              if(arr[mid]<arr[high])
               {
                   high=mid-1;
               }
               else
               {
                   low=mid+1;
               } 
           }
       }
       return small;
    }
};