// TC - O(nlogn)
// SC - O(2*n)

class Solution {
public:
    typedef pair<int, int> P; 
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        priority_queue<P, vector<P>> maxPq;
        priority_queue<P, vector<P>, greater<P>> minPq;

        int low = 0, high = 0;

        int size = 0;

        while(high < n) {
            maxPq.push({nums[high], high});
            minPq.push({nums[high], high});
            while(maxPq.top().first - minPq.top().first > limit) {
                low = min(maxPq.top().second, minPq.top().second) + 1;

                while(maxPq.top().second < low) {
                    maxPq.pop();
                }
                while(minPq.top().second < low) {
                    minPq.pop();
                }
            }
            size = max(size, high - low + 1);
        
            high++;
    }
    return size;
    }
};


//TC - O(nlogn)
//SC - O(n)

class Solution {
public:
    typedef pair<int, int> P; 
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        multiset<int> st;

        int low = 0, high = 0;

        int size = 0;

        while(high < n) {
            st.insert(nums[high]);
            while(*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[low]));
                low++;
            }
            size = max(size, high - low + 1);
        
            high++;
    }
    return size;
    }
};
