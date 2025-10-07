#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int longWallet = wallet[0] >= wallet[1] ? wallet[0] : wallet[1];
    int shortWallet = wallet[0] >= wallet[1] ? wallet[1] : wallet[0];

    while (true){
        int& longBill = bill[0] >= bill[1] ? bill[0] : bill[1];
        int shortBill = bill[0] >= bill[1] ? bill[1] : bill[0];
        
        if (longWallet >= longBill && shortWallet >= shortBill) break;
        
        longBill /= 2;
        ++answer;
    }
    return answer;
}