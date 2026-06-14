class TimeMap {
    unordered_map<string, map<int, string>> data;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {        
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);
        if (it == end(data)) {
            return "";
        }

        auto pos = it->second.upper_bound(timestamp);
        if (pos == end(it->second)) --pos;
        if (pos->first > timestamp) {
            if (pos == begin(it->second)) return "";
            --pos;
        }
        return pos->second;
    }
};
