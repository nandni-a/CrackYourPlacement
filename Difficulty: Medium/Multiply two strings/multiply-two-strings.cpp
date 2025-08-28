class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        bool neg = false;
        if (!s1.empty() && s1[0] == '-') {
            neg = !neg;
            s1 = s1.substr(1);
        }
        if (!s2.empty() && s2[0] == '-') {
            neg = !neg;
            s2 = s2.substr(1);
        }

        while (s1.size() > 1 && s1[0] == '0') s1.erase(s1.begin());
        while (s2.size() > 1 && s2[0] == '0') s2.erase(s2.begin());

        if (s1 == "0" || s2 == "0") return "0";

        int m = s1.size(), n = s2.size();
        vector<int> ans(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }

        string res;
        int i = 0;
        while (i < ans.size() && ans[i] == 0) i++;
        for (; i < ans.size(); i++) res.push_back(ans[i] + '0');

        if (res.empty()) return "0";
        if (neg) res = "-" + res;
        return res;
    }
};
