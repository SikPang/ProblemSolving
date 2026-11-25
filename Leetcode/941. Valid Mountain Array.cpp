class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] >= arr[1]) return false;

        bool isIncreasing = true;

        for (int i=2; i<arr.size(); ++i){
            if (arr[i] == arr[i-1]) return false;

            if (isIncreasing && arr[i] < arr[i-1]) {
                isIncreasing = false;
                continue;
            }

            if (!isIncreasing && arr[i] > arr[i-1]){
                return false;
            }
        }
        return !isIncreasing;
    }
};