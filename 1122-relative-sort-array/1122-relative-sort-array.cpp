class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int> mp;
    map<int,int> uniq;
    
    for(int i = 0 ; i < arr2.size(); i++) mp[arr2[i]] = 0;
    
    for(int i = 0 ; i < arr1.size(); i++)
      if(mp.count(arr1[i])) mp[arr1[i]]++;
      else if(uniq.count(arr1[i])) uniq[arr1[i]]++;
           else uniq[arr1[i]] = 1;
    
    int i = 0;
    for(int j = 0;j < arr2.size(); j++){
      int t = mp[arr2[j]];
      for(int w = 0;w < t; w++)
        arr1[i++] = arr2[j];
    }
    
    for(auto it = uniq.begin() ;it != uniq.end(); it++)
      for(int j = 0;j < it->second; j++)
        arr1[i++] = it->first;
       
    return arr1;
    }
};