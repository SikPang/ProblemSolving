class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> result(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = mul + result[p2];

                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        string answer;
        int i = 0;

        while (i < result.size() && result[i] == 0) {
            ++i;
        }

        while (i < result.size()) {
            answer.push_back(result[i] + '0');
            ++i;
        }

        return answer.empty() ? "0" : answer;
    }
};