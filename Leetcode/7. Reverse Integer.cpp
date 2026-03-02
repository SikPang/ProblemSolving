class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        string str;
        bool isMinus = x < 0;
        if (isMinus){
            str.push_back('-');
        }

        while (x % 10 == 0){
            x /= 10;
        }

        while (x != 0){
            str.push_back(abs(x % 10) + '0');
            x /= 10;
        }
        cout << str;

        int intVal;
        try{
            intVal = stoi(str);
        } catch (std::out_of_range){
            return 0;
        }
        return intVal;
    }
};