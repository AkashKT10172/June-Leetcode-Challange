// brute force
//TC - O(n2)
//SC - O(1)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
                for(int j = i;  j < nums.size(); j++) {
                    sum += nums[j];
                    if(sum % k == 0 ) cnt++;
                }
        }
        return cnt;
    }

};

// optimal 
// TC - O(n)
// SC - O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        map<int, int> moduloMap;
        // [4 9 9 7 4 5]
        // 0 & 1 both modulo with k is 4 and when we see the array
        // we see that this sub array (0, 1] 
        // is divisible by k
        // similarly index 0 & 2 have same modulo
        // we see sub array (0, 1, 2] is divisible by k.
        // so we store modulo and number of time it occurs.....
        // map / hash_map
        int subarrays = 0;
        for(int i = 0; i<n; i++) {
            int x = (prefixSum[i] % k >= 0) ? (prefixSum[i] % k) : (prefixSum[i] % k + k);
            // for case of x check this array [2 -6 3 1 2 8 2 1]
            // we can write 7*n - 4 = 7*(n-1) + 3
            if(x == 0) subarrays++;
            if(moduloMap.find(x) != moduloMap.end()) {
                subarrays += moduloMap[x];
            }

            moduloMap[x]++;
        }
        for(auto it : moduloMap) cout<<it.first<<" "<<it.second<<" "; cout<<endl;
        return subarrays;
    }
    
};
