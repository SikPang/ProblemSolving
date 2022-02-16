import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public int[] solution(String[] id_list, String[] report, int k) {
		int[] answer = new int[id_list.length];
		int[] reportCnt = new int[id_list.length];
		int[] duplicate = new int[report.length];
		String[][] seperate = new String[report.length][2];
		Map<String, Integer> nameToIndex = new HashMap();
		
		for(int i=0; i<id_list.length; i++) {
			nameToIndex.put(id_list[i], i);
		}

		Arrays.sort(report);
		for (int i = 0; i < seperate.length; i++) { // 나눠서 채우기
			seperate[i] = report[i].split(" ");
		}
        
		for (int i = 0; i < seperate.length - 1; i++) { // 중복 체크
			if (seperate[i][0].equals(seperate[i+1][0]) &&seperate[i][1].equals(seperate[i+1][1]))
				duplicate[i] = 1;
		}
		
		// seperate의 뒤엣 값 넣었을 때 id_list의 index return
		for (int i = 0; i < seperate.length; i++) { 	// 신고 카운트 체크
			if (duplicate[i] != 1) {
				reportCnt[nameToIndex.get(seperate[i][1])]++;
			}
		}

		// 신고 k번 이상 당한 sperate 뒤엣값 사람을 찾아서 그걸 찍은 seperate 앞엣값 사람들에게 메일 보냄		
		for (int i = 0; i < seperate.length; i++) {
			if(duplicate[i]!=1 && reportCnt[nameToIndex.get(seperate[i][1])] >= k) {
				answer[nameToIndex.get(seperate[i][0])]++;
			}
		}
		return answer;
	}
}