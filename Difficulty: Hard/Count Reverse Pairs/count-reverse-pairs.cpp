class Solution {
  public:
    int cnt=0;
    void merge(vector<int>&arr,int l,int mid,int h){
        vector<int>temp;
        int left=l;
        int right=mid+1;
        while(left<=mid && right<=h){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
             left++;
            
        }
        while(right<=h){
            temp.push_back(arr[right]);
            right++;
            
        }
        for(int i=l;i<=h;i++){
            arr[i]=temp[i-l];
        }
    }
    void countPair(vector<int>&arr,int l,int mid,int h){
        int r=mid+1;
        for(int i=l;i<=mid;i++){
            while(r<=h && arr[i]>2*arr[r]){
                r++;
            }
            cnt+= (r-(mid+1));
        }
    }
    void mergeSort(vector<int>&arr,int l,int h){
        if(l>=h) return ;
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        countPair(arr,l,mid,h);
        merge(arr,l,mid,h);
    }
    int countRevPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        mergeSort(arr,0,n-1);
        return cnt;
        
    }
};