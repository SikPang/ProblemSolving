#include <vector>
using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;

    denum1 *= num2;
    denum2 *= num1;

    denum1 += denum2;
    num1 *= num2;

    int n = 2;
    while (true)
    {
        if (n > denum1 || n > num1) break;

        if (denum1 % n == 0 && num1 % n == 0)
        {
            denum1 /= n;
            num1 /= n;
        }
        else
            ++n;
    }

    answer.push_back(denum1);
    answer.push_back(num1);

    return answer;
}