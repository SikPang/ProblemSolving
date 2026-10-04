class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        answer.reserve(10001);

        for (int cur=left; cur<=right; ++cur){
            int num = cur;
            bool isDividingNumber = true;

            while (num > 0){
                int remainder = num % 10;
                if (remainder == 0 || cur % remainder != 0) {
                    isDividingNumber = false;
                    break;
                }
                num /= 10;
            }

            if (isDividingNumber) {
                answer.push_back(cur);
            }
        }
        return answer;
    }
};