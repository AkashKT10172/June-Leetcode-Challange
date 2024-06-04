class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> mp;
        for(int i = 0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        int odd = 0;
        int len = 0;
        for(auto it : mp) {
            cout<<it.second<<endl;
            if(it.second % 2 == 0) len += it.second;
            else {
                if(odd >= it.second) len += it.second - 1;
                else {
                    len += max(0, odd - 1);
                    odd = it.second;
                }
            }
            cout<<len<<endl;
        }
        return len + odd;
    }
};
