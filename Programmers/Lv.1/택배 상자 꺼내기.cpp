#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int w, int num) {
    int row = (int)ceil(n / (float)w);
    vector<vector<bool>> boxes(row, vector<bool>(w, true));
    
    // 맨 윗층 상자 빼기
    bool isRightDir = (row - 1) % 2 == 0;
    int startNum = row * w - w + 1;
    int boxCount = n - startNum + 1;
    
    for (int i = isRightDir? 0 : w - 1; i != (isRightDir ? w : -1); i += (isRightDir ? 1 : -1)){
        if (boxCount > 0){
			boxCount--;
		} else {
			boxes[row-1][i] = false;
		}
    }

    int count = 0;
    for (int i = 0; i < row; ++i){
        isRightDir = i % 2 == 0;
        for (int j = isRightDir? 0 : w - 1; j != (isRightDir ? w : -1); j += (isRightDir ? 1 : -1)){
            if (++count == num){
                int answer = 0;
                for (int k = i; k < row; ++k){
                    if (boxes[k][j] == true) ++answer;
                }
                return answer;
            }
        }
    }
    
    return -1;
}