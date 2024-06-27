class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        // center node must appear in every node, means the common node of any two edges will be our              answer
        return e[0][0]==e[1][0] || e[0][0]==e[1][1] ? e[0][0] : e[0][1];
    }
};