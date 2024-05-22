class Solution {
public:
    vector<vector<string>> partition(string s) {
                vector<vector<string>> res;
        int n = s.size();
        function<void(int, vector<string>)> bt = [&](int i, vector<string> l) {
            if (i == n) {
                res.push_back(l);
                return;
            }
            for (int j = i + 1; j <= n; j++) {
                string sub = s.substr(i, j - i);
                if (sub == string(sub.rbegin(), sub.rend())) {
                    l.push_back(sub);
                    bt(j, l);
                    l.pop_back();
                }
            }
        };
        bt(0, {});
        return res;


        
    }
};