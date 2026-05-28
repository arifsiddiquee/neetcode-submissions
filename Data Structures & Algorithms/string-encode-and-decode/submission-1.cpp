class Solution {
    const char SEPARATOR = '#';
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) {
            res += to_string(s.size());
            res += SEPARATOR;
            res += s;            
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        int pos = 0;
        vector<string> res;

        while (pos < s.size()) {
            int len = 0;
            for (int i = pos; i < s.size(); i++) {
                if (s[i] == SEPARATOR) {
                    pos = i + 1;
                    break;
                }
                len = len * 10 + (s[i] - '0');
            }
            res.push_back(s.substr(pos, len));
            cout << res.back() << endl;
            pos += len;
        }
        return res;
    }
};
