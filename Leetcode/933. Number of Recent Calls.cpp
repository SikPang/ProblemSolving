class RecentCounter {
private:
    vector<int> buf;
    int leftIdx = 0;

public:
    RecentCounter() {}
    
    int ping(int t) {
        buf.push_back(t);
        while (buf[leftIdx] < t-3000){
            ++leftIdx;
        }
        return buf.size() - leftIdx;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */