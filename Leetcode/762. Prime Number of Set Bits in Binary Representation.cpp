class Solution {
private:
    unordered_map<int, bool> primeNums;

private:
    int countOneBits(int num){
        int count = 0;
        while (num > 0){
            if (num % 2 == 1){
                ++count;
            }
            num /= 2;
        }
        return count;
    }

    bool isPrimeNumber(int num){
        auto iter = primeNums.find(num);
        if (iter != primeNums.end()){
            return iter->second;
        }

        for (int i=2; i*i<=num; ++i){
            if (num % i == 0) {
                primeNums.insert({num, false});
                return false;
            }
        }

        primeNums.insert({num, true});
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int answer = 0;

        for (int i=left; i<=right; ++i){
            int count = countOneBits(i);
            if (count > 1 && isPrimeNumber(count)){
                ++answer;
            }
        }
        return answer;
    }
};