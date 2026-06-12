class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;

        for (int i=0; i<operations.size(); ++i){
            try{
                int integer = stoi(operations[i]);
                record.push(integer);
            } catch(std::invalid_argument){
                if (record.size() == 0) continue;

                switch (operations[i][0]){
                    case '+':
                    if (record.size() > 1) {
                        int a = record.top();
                        record.pop();
                        int b = record.top();
                        record.push(a);
                        record.push(a+b);
                    } else if (record.size() == 1){
                        record.push(record.top());
                    }
                    break;
                    case 'D':
                    record.push(record.top() * 2);
                    break;
                    case 'C':
                    record.pop();
                    break;
                }
            }
        }

        int sum = 0;
        while (record.size() > 0){
            sum += record.top();
            record.pop();
        }
        return sum;
    }
};