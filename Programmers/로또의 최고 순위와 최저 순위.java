import java.util.ArrayList;

public class Solution {
	public int[] solution(int[] lottos, int[] win_nums) {
		int correctCnt = 0;
		int zeroCnt = 0;
		int min = 0;
		int max = 0;
		ArrayList<Integer> list = new ArrayList<>();

		for (int i = 0; i < lottos.length; i++) {
			list.add(lottos[i]);
		}

		for (int i = 0; i < list.size(); i++) {
			if (list.contains(win_nums[i]))
				correctCnt++;
			if (list.get(i) == 0)
				zeroCnt++;
		}

		switch (correctCnt) {
		case 2:
			min = 5;
			break;
		case 3:
			min = 4;
			break;
		case 4:
			min = 3;
			break;
		case 5:
			min = 2;
			break;
		case 6:
			min = 1;
			break;
		default:
			min = 6;
			break;
		}

		switch (correctCnt + zeroCnt) {
		case 2:
			max = 5;
			break;
		case 3:
			max = 4;
			break;
		case 4:
			max = 3;
			break;
		case 5:
			max = 2;
			break;
		case 6:
			max = 1;
			break;
		default:
			max = 6;
			break;
		}

		int[] answer = { max, min };
		return answer;
	}
}