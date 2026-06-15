class Solution {
public:
    int myAtoi(string str){
        int		i = 0;
        int		minus = 1;
        long	num = 0;

        while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
            ++i;

        if (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-')
                minus *= -1;
            ++i;
        }

        while (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';

            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
                return minus == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            ++i;
        }
        return (num * minus);
    }
};