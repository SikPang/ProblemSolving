class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string str;

        while (n > 0){
            int cur = n % 10;
            if (cur != 0){
                str.push_back(cur + '0');
            }
            n /= 10;
        }

        reverse(str.begin(), str.end());

        long long sum = 0;
        long long num = stoi(str);
        for (int i=0; i<str.size(); ++i){
            sum += str[i] - '0';
        }

        return num * sum;
    }
};