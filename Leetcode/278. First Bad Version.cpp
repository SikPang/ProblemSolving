// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int findFirstBadVersion(long start, long end){
        if (start == end) return start;

        long cur = (end + start) / 2;

        if (start == cur && end - 1 == start){
            if (isBadVersion(start)) return start;
            else return end;
        }

        if (isBadVersion(cur)){
            return findFirstBadVersion(start, cur);
        } else{
            return findFirstBadVersion(cur, end);
        }
    }

public:
    int firstBadVersion(int n) {
        return findFirstBadVersion(1, n);
    }
};