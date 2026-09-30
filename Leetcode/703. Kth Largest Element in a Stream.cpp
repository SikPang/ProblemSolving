class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> nums;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int i=0; i<nums.size() && i<k; ++i){
            this->nums.push(nums[i]);
        }
    }

    int add(int val) {
        if (nums.size() < k) {
            nums.push(val);
            return nums.top();
        }

        int min = nums.top();
        if (min > val){
            return min;
        }

        nums.pop();
        nums.push(val);
        return nums.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */