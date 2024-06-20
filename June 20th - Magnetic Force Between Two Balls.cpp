// typical binary search on answer
// nlogn

class Solution {
public:
    bool check(vector<int> arr, int mid, int m) {
        int balls = m;
        int last = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - last >= mid) {
                balls--;
                last = arr[i];
            }
        }
        if(balls <= 1) return true;
        else return false; 
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        long long low = 1, high = 1e12;
        while(low <= high) {
            int mid = low - (low - high) / 2;
            if(check(position, mid, m) == true) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
