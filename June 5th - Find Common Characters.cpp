//brute force approach
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        map<char, int> mp;
        for(int i = 0; i<words[0].size(); i++) {
            mp[words[0][i]]++;
        }
        for(auto  it : mp) cout<<it.first<<" "; cout<<endl;
        for(int i = 1; i < n; i++) {
            map<char, int> global;
            for(int j = 0;  j < words[i].size(); j++) {
                if(mp.find(words[i][j]) != mp.end()) {
                    mp[words[i][j]]--;
                    if(mp[words[i][j]] == 0) mp.erase(words[i][j]);
                    global[words[i][j]]++;
                }
            }
            for(auto  it : global) cout<<it.first<<" "; cout<<endl;
            mp = global;
        }
        vector<string> res;
        for(auto it : mp) {
            int x = it.second;
            while(x) {
                string s  = "";
                s.push_back(it.first);
                res.push_back(s);
                x--;
            } 
        }
        return res;
    }
};

//optimal approach TC = O( words.size() * (words[i].size() + 26) )
// SC = O(26 + 26)
// there is extra space for string but that is required to return the answer 
// the extra TC for copy from vector<int> to vector<string> O(26 * max freq of common element)

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> a(26, INT_MAX);
        for(int i = 0; i < n; i++) {
            vector<int> arr(26, 0);
            for(int j = 0;  j < words[i].size(); j++) {
                arr[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                a[j] = min(a[j], arr[j]);
            }
        }
       vector<string> res;
        for(int i = 0; i < 26; i++) {
            int x = a[i];
            while(x) {
                string s  = "";
                s.push_back(i + 'a');
                res.push_back(s);
                x--;
            } 
        }
        return res;
    }
};
