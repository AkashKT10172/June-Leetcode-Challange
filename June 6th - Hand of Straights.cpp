//Brute Force
//TC = O(nlogn + n*n)
//SC = O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int  n = hand.size();
        vector<int> hash(n);
        sort(hand.begin(), hand.end());
        for(int i = 0; i<n; i++) {
            if(hash[i] == 1) continue;
            int k = groupSize;
            int cons = hand[i];
            hash[i] = 1;
            k--;
            for(int j = i+1; j<n; j++) {
                if(hash[j] == 1) continue;
                if(k==0) break;
                if(hand[j] == (cons + 1)) {
                    hash[j] = 1;
                    cons++;
                    k--;
                }
            }
            if(k>0) return false;
        }
        return true;
    }
};

//Optimal or Better
//TC = O(nlogn) + [O(n*groupSize) ~~ O(n)] 
//SC = O(uniqueElements)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int  n = hand.size();
        map<int, int> mp;
        for(int i = 0; i<n; i++) mp[hand[i]]++;
        sort(hand.begin(), hand.end());
        for(int i = 0; i<n; i++) {
            if(mp[hand[i]] == 0) continue;
            for(int j = 0; j < groupSize; j++) {
                int currCard = hand[i] + j;
                if(mp[currCard] == 0) {
                    return false;
                }
                mp[currCard]--;
            }
        }
        return true;
    }
};
