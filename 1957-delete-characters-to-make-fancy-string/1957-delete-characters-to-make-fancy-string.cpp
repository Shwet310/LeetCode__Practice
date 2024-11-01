class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int cnt = 1;
     
        for(int i=1; i<s.size(); i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt<3) ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};