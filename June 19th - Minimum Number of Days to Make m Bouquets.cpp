// TC - O(n * log(max(bloomDay)))
// SC - O(1)


class Solution {
public:
        int max_value(vector<int> v){
            int ans=INT_MIN;
            for(int i:v){
                ans=max(ans,i);
            }
            return ans;
        }
        int minDays(vector<int>& bloomDay, long m, long k) {
        int n = bloomDay.size();
        if(m * k > n) return -1;

        auto adjacentMilGya = [&](vector<int> bloomDay, int mid, int m, int k) {
            int adjacent = 0;
            int bs = 0;
            for(int i = 0; i < n; i++) {
                if(bloomDay[i] <= mid) adjacent++;
                else adjacent = 0;
                if(adjacent == k) {
                    bs++;
                    adjacent = 0;
                }
            }
            if(bs >= m) return true;
            else return false;
        };

        int low = 1, high = max_value(bloomDay);
        while(low <= high) {
            int mid = low - (low - high) / 2;
            if(adjacentMilGya(bloomDay, mid, m , k) == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
