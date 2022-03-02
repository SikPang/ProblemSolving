class Solution {
    public int solution(String name) {
        int[] answer = new int[2];
        StringBuilder sb;
        int index = 0;
        int gap = 0;
        int rightIndex = 0;
        int leftIndex = 0;
        boolean isBreaked = false;

        for (int k = 0; k < 2; k++) {   // 기본 방법과 처음에서 반대로 가는 방법 총 두가지 중 더 최소의 수 리턴
            sb = new StringBuilder();
            for (int i = 0; i < name.length(); i++)
                sb.append("A");
            index = 0;
            gap = 0;
            rightIndex = 0;
            leftIndex = 0;
            isBreaked = false;
            while (!sb.toString().equals(name)) {
                if (name.charAt(index) != 'A') {
                    // 1. 현재 인덱스에서 알파벳 격차 찾기 (위로 올리는게 빠른지, 아래로 내리는게 빠른지 비교)
                    if (name.charAt(index) - 'A' > 'Z' - name.charAt(index) + 1)
                        gap = 'Z' - name.charAt(index) + 1;
                    else
                        gap = name.charAt(index) - 'A';

                    // 2. 조정하고, 조정한 만큼 answer 값 올리기
                    answer[k] += gap;
                    sb.setCharAt(index, name.charAt(index));
                }
                // 3. 제일 가까운 A 아닌 인덱스 찾기 (좌로 가는게 빠를지, 우로 가는게 빠를지 비교)
                rightIndex = 0;
                for (int i = index;; i++) {
                    if (rightIndex >= index + name.length()) {
                        isBreaked = true;
                        break;
                    }
                    if (i == name.length()) // 최대 인덱스를 지나면 0으로 초기화
                        i = 0;
                    if (name.charAt(i) != 'A' && name.charAt(i) != sb.charAt(i)) break;
                    rightIndex++;
                }
                if (isBreaked) break;
                
                leftIndex = 0;
                for (int i = index;; i--) {
                    if (rightIndex <= index - name.length()) {
                        isBreaked = true;
                        break;
                    }
                    if (i == -1) // 최소 인덱스를 지나면 name.length()-1로 초기화
                        i = name.length() - 1;
                    if (name.charAt(i) != 'A' && name.charAt(i) != sb.charAt(i)) break;
                    leftIndex++;
                }
                if (isBreaked) break;

                // 4 .다음 인덱스로 가기
                if (k == 1 && index == 0) { // 2번째 반복의 첫 인덱스에서만 반대로
                    if (rightIndex < leftIndex) {
                        index -= leftIndex;
                        if (index < 0)
                            index += name.length();
                        answer[k] += leftIndex;
                    } else {
                        index += rightIndex;
                        if (index > name.length() - 1)
                            index -= name.length();
                        answer[k] += rightIndex;
                    }
                } else {
                    if (rightIndex < leftIndex) {
                        index += rightIndex;
                        if (index > name.length() - 1)
                            index -= name.length();
                        answer[k] += rightIndex;
                    } else {
                        index -= leftIndex;
                        if (index < 0)
                            index += name.length();
                        answer[k] += leftIndex;
                    }
                }
            }
        }

        if (answer[0] > answer[1])
            return answer[1];
        else
            return answer[0];
    }
}