//TC - O(nlogn)
//SC - O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> mp;
        for(int i = 0; i< arr1.size(); i++) {
            mp[arr1[i]]++;
        }
        for(int i = 0; i< arr2.size(); i++) {
            for(int j = 0; j<arr1.size(); j++) {
                if(arr1[j] == arr2[i]) {
                    res.push_back(arr1[j]);
                    mp[arr1[j]]--;
                }
            }
        }
        for(auto it : mp) {
            int x = it.second;
            while(x--){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
