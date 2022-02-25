class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int area = brown + yellow;

        // (가로-2) x (세로-2) = yellow
        for (int i = 0; i < area; i++) {
            for (int j = 0; j <= i; j++) {
                if (i*j == area && (i-2) * (j-2) == yellow) {
                    answer[0] = i;
                    answer[1] = j;
                    break;
                }
            }
            if (answer[0] != 0) break;
        }
        return answer;
    }
}