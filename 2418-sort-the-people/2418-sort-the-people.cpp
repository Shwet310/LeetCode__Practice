class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for (int i = 0; i < size(heights); ++i) {
             int mx = distance(begin(heights), max_element(next(begin(heights), i), end(heights)));
             swap(heights[i], heights[mx]);
             swap(names[i], names[mx]);
         }
         return names;
    }
};