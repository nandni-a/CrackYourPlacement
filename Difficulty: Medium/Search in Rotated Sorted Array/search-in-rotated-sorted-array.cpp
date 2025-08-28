class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int l = 0, r = arr.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (arr[mid] == key) return mid;
            
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= key && key < arr[mid]) {
                    r = mid - 1;  
                } else {
                    l = mid + 1; 
                }
            }
            
            else {
                if (arr[mid] < key && key <= arr[r]) {
                    l = mid + 1;  
                } else {
                    r = mid - 1; 
                }
            }
        }
        return -1;
    }
};
