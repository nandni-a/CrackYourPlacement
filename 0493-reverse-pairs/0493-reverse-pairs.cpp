class Solution {
public:
    void merge(int start, int end, int mid, vector<int>& nums, int &count) {
        vector<int> left(nums.begin() + start, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + end + 1);

        int n1 = left.size(), n2 = right.size();
        int i = 0, j = 0;

        // Counting reverse pairs
        for (i = 0, j = 0; i < n1; i++) {
            while (j < n2 && left[i] > 2LL * right[j]) {
                j++;
            }
            count += j;
        }

        // Merge the two sorted halves into the original array
        i = 0;
        j = 0;
        int k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while (i < n1) {
            nums[k++] = left[i++];
        }

        while (j < n2) {
            nums[k++] = right[j++];
        }
    }

    void mergeSort(int start, int end, vector<int>& nums, int &count) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, nums, count);
        mergeSort(mid + 1, end, nums, count);
        merge(start, end, mid, nums, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(0, nums.size() - 1, nums, count);
        return count;
    }
};

