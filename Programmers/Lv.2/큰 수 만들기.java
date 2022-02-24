class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        String answer = "";
        int max = -1;
        int maxIndex = 0;
        int prevIndex = 0;
        int length = number.length() - k;

        while (k != 0) {
            if (length <= sb.length()) break;
            max = -1;

            for (int j = 0; j < k+1; j++) { // 앞에서부터 k+1번째 수 중에서 최댓값 인덱스 구하기
                if (max < number.charAt(j+prevIndex)-'0') {
                    max = number.charAt(j+prevIndex)-'0';
                    maxIndex = j;
                }
            }
            sb.append(max);
            prevIndex = prevIndex + maxIndex + 1;
            k -= maxIndex;
        }

        if (length > sb.length()) {         // 나머지 수 채우기
            for (int i = prevIndex; i < number.length(); i++)
                sb.append(number.charAt(i)-'0');
        }

        answer = sb.toString();
        return answer;
    }
}