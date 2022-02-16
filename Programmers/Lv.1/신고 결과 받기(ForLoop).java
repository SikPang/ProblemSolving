import java.util.Arrays;
import java.util.Arrays;

public class Solution {
	public int[] solution(String[] id_list, String[] report, int k) {
		int[] answer = new int[id_list.length];
		int[] reportCnt = new int[id_list.length];
		int[] duplicate = new int[report.length];
		String[][] seperate = new String[report.length][2];

		Arrays.sort(report);
		for (int i = 0; i < seperate.length; i++) { // 나눠서 채우기
			seperate[i] = report[i].split(" ");
		}

		for (int i = 0; i < seperate.length - 1; i++) { // 중복 체크
			if (seperate[i][0].equals(seperate[i+1][0]) &&seperate[i][1].equals(seperate[i+1][1]))
				duplicate[i] = 1;
		}

		for (int i = 0; i < seperate.length; i++) { // 신고 카운트 체크
			if (duplicate[i] != 1) {
				for (int j = 0; j < id_list.length; j++) {
					if (reportCnt[j] < k && seperate[i][1].equals(id_list[j])) {
						reportCnt[j]++;
						break;
					}
				}
			}
		}

		for (int i = 0; i < reportCnt.length; i++) { // 신고 카운트 k 이상인 사람 체크
			if (reportCnt[i] >= k) {
				for (int j = 0; j < seperate.length; j++) { // 신고 카운트 k 이상인 사람을 신고한 사람에게 메일 보내기
					if (duplicate[j] != 1 && seperate[j][1].equals(id_list[i])) {
						for (int l = 0; l < id_list.length; l++) {
							if (seperate[j][0].equals(id_list[l])) {
								answer[l]++;
								break;
							}
						}
					}
				}
			}
		}
		return answer;
	}
}