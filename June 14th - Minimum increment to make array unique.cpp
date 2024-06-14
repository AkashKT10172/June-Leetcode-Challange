// brute force 
// store all elements in a map and check for each iteration if the element is present in the map ?
// increase the element and check again
// Time = O(n2) in worst case
// space = O(n)

class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        map<int, int> mp;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            while(mp.find(arr[i]) != mp.end()) {
                arr[i]++;
                cnt++;
            }
            mp[arr[i]]++;
        }
        return cnt;
    }
};

//optimal 
// time = O(NlogN)
// space = O(1)

class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] <= arr[i-1]) {
                cnt += arr[i-1] - arr[i] + 1;
                arr[i] = arr[i-1] + 1;
            }
        }
        return cnt;
    }
};
