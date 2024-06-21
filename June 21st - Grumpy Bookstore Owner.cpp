// TC - O(N)
// SC - O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& grumpy, int minutes) {
        int n = c.size();
        int maxsum = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {sum+=c[i]; c[i] = 0;}
        }
        
        maxsum = sum;

        for(int i = 0; i < min(minutes, n); i++) {
                sum+= c[i];
        }

        maxsum = max(sum, maxsum);

        int i = 1, j = minutes;

        while(j < n) {
            sum+=c[j]; sum-=c[i-1];
            maxsum = max(sum, maxsum);
            j++; i++;
        }

        return maxsum;
    }
};
