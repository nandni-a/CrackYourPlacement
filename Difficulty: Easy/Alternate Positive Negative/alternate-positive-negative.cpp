class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;

        for (int x : arr) {
            if (x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        vector<int> ans;
        int i = 0, j = 0;

        // Alternate positives and negatives, starting with positive
        while (i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        // Append remaining positives
        while (i < pos.size())
            ans.push_back(pos[i++]);

        // Append remaining negatives
        while (j < neg.size())
            ans.push_back(neg[j++]);

        arr = ans;
    }
};