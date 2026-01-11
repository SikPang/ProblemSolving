class NumArray {
private:
    vector<int>* curNums;

public:
    NumArray(vector<int>& nums) {
        curNums = &nums;
    }
    
    int sumRange(int left, int right) {
        int ret = 0;
        for (int i=left; i<=right; ++i){
            ret += (*curNums)[i];
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */