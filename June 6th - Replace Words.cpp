// my only approach for today 

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        set<string> st; // a set to store all the words in dictionary

        // inserting words in dictionary O(NlogN)

        for(int i = 0; i < d.size(); i++) {
            st.insert(d[i]);
        }

        vector<string> vec;  // a vector to store all the words in sentence
        
        string chotu = "";

        // inserting each and every word of the sentence in a vector O(Size)
        
        for(int i = 0; i<s.size(); i++) {
            if ( s[i] == ' ') {
                vec.push_back(chotu);
                chotu = "";
            } else {
                chotu.push_back(s[i]);
            }
            if (i == s.size() - 1) vec.push_back(chotu);
        }

        // string to store the result
        string res;

        // O(size * logN)

        for(int i = 0; i<vec.size(); i++) {
            string chotu = "";
            for(int j = 0; j<vec[i].size(); j++) {
                chotu.push_back(vec[i][j]);
                if(st.find(chotu) != st.end()) {
                    vec[i] = chotu;
                    break;
                }
            } 
        }

        // storing the result ... O(res.size())

        for(int i = 0 ; i < vec.size(); i++) {
            res += vec[i] + " ";
        }

        // popping the extra space added
        
        if(res.back() == ' ') res.pop_back();
        
        return res;
    }
};
