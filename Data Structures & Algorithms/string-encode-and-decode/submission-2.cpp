class Solution {
public:
    const char DELIMITER = ',';

    string encode(vector<string>& strs) {
        int count = strs.size();
        string encoded = "";
        // Add count
        encoded += to_string(count);
        // Add each string size;
        for (auto& s : strs) {
            encoded += DELIMITER;
            encoded += to_string(s.size());
            encoded += DELIMITER;
            encoded += s;
        }

        cout << encoded << endl;

        return encoded;
    }

    int getNextInt(string& s, int& index) {
        int num = 0;
        while (index < s.size() && s[index] != DELIMITER) {
            num = num * 10 + (s[index] - '0');
            index++;
        }
        // Consume the delimiter
        index++;

        return num;
    }

    vector<string> decode(string s) {
        int index = 0;
        int count = getNextInt(s, index);

        if (count == 0) return {};

        vector<string> result(count);

        for (int i = 0; i < count; i++) {
            int len = getNextInt(s, index);
            result[i] = s.substr(index, len);
            index += len;
            index++;
        }

        return result;
    }
};
