import java.util.ArrayList;

class Solution {
	int cnt = 0;

	public int solution(String numbers) {
		StringBuilder sb = new StringBuilder();
		ArrayList<Integer> indexList = new ArrayList<>();
		ArrayList<Integer> primeList = new ArrayList<>();
		Search(numbers, 0, sb, indexList, primeList);
		return cnt;
	}

	private void Search(String numbers, int depth, StringBuilder sb, ArrayList<Integer> indexList, ArrayList<Integer> primeList) {
		if (depth == numbers.length() + 1)return;

		if (primeList.size() == 0 || !primeList.contains(Integer.parseInt(sb.toString()))) {
			if (depth != 0 && CheckPrime(Integer.parseInt(sb.toString()))) {
				cnt++;
				primeList.add(Integer.parseInt(sb.toString()));
			}
		}
		depth++;
		for (int i = 0; i < numbers.length(); i++) {
			if (indexList.size() != 0 && indexList.contains(i)) continue;

			sb.append(numbers.charAt(i));
			indexList.add(i);

			Search(numbers, depth, sb, indexList, primeList);

			sb.deleteCharAt(sb.length() - 1);
			indexList.remove(indexList.size() - 1);
		}
	}

	private boolean CheckPrime(int num) {
		int cnt = 0;
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				cnt++;
				break;
			}
		}
		if (cnt == 0 && num != 1 && num != 0) // 소수임
			return true;
		else
			return false;
	}
}