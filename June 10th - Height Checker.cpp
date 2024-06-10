// brute force works itself, TC - O(n + nlogn), SC - O(n)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> bubbu = heights;
        sort(bubbu.begin(), bubbu.end());
        int cnt = 0;
        for(int i = 0 ; i < heights.size() ; i++) {
            if(heights[i] != bubbu[i]) cnt++;
        }
        return cnt;
    }
};
