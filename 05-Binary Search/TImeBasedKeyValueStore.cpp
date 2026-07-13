class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        //empty constructor
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty() || mp[key][0].first > timestamp) return "";
        int l=0, r=mp[key].size()-1;
        int ans =0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mp[key][mid].first == timestamp) return mp[key][mid].second;
            else if(mp[key][mid].first < timestamp) {
                ans = mid;
                l = mid+1;
            }
            else r=mid-1;
        }
        return mp[key][ans].second;
    }
};
