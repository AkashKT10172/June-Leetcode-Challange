// SC = O(2*n) + O(n)
//TC = O(n) + O(nlogn) + O(k + n)  === O(nlogn)


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        
        vector<pair<int, int>> vrr(n);
        
        for(int i = 0; i < n; i++) {
            vrr[i].first = capital[i];
            vrr[i].second = profits[i];
        }
        
        sort(vrr.begin(), vrr.end());

        priority_queue<int> pq;

        int i = 0;

        while(k) {
            while(i < n && w >= vrr[i].first) {
                pq.push(vrr[i].second);
                i++;
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
