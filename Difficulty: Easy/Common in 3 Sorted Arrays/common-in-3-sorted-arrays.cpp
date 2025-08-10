class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
    
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        while(i < n1 && j < n2 && k < n3)
        {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                if(ans.empty() || ans.back() != arr1[i])
                    ans.push_back(arr1[i]); 
                i++;
                j++;
                k++;
            }
            else
            {
                int mini = min({arr1[i], arr2[j], arr3[k]});
                if(arr1[i] == mini) i++;
                if(arr2[j] == mini) j++;
                if(arr3[k] == mini) k++;
            }
        }
        return ans;

    }
};