// brute force approach 
// O(n*n), gives TLE

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++) {
            int sum = nums[i];
            for(int j = i + 1; j<nums.size(); j++) {
                sum += nums[j];
                if(sum%k == 0) return true;
            }
        }
        return false;
    }
};

// better approach
// TC - O(n * log(n)), can be brought to O(n) by using an unordered map, but I always refrain from using it.... due to possible chances of collisions.
// SC - O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int hash = 0;
        for (int i = 0; i < n; i++) {
            hash += nums[i];
            if (hash % k == 0 && i > 0)
                return true;
            if (mp.find(hash % k) != mp.end() && (i - mp[hash % k]) > 1)
                return true;
            if (mp.find(hash % k) == mp.end())
                mp[hash % k] = i;
        }
        return false;
    }
};
