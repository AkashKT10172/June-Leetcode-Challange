class Solution {
public:
    int appendCharacters(string s, string t) {
        int sp = 0, tp = 0;
        while(tp< t.size() && sp< s.size()) {
            if(s[sp] == t[tp]) {
                sp++; tp++;
            }
            else sp++;
        }
        return t.size() - tp;
    }
};
