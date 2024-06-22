// TC - O(N)
// SC - O(1)

class Solution {
public:
    int cntOdds(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, odds = 0, cnt = 0;
        while(r < n) {
            if(nums[r] % 2 == 1) odds++;
            if(odds <= k) cnt += r-l+1;
            else {
                while(odds > k) {
                    if(nums[l] % 2 == 1) odds--;
                    l++;
                }
                cnt += r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntOdds(nums, k) - cntOdds(nums, k-1);
    }
};
