import java.util.ArrayList;

public class Solution {
	public String solution(String new_id) {
		ArrayList<Character> list = new ArrayList<>();

		for (int i = 0; i < new_id.length(); i++) {
			list.add(new_id.charAt(i));
		}

		for (int i = 0; i < list.size(); i++) {
			if (list.get(i) >= 'A' && list.get(i) <= 'Z')
				list.set(i, (char) (list.get(i) + 32));
			else {
				switch (list.get(i)) {
				case '.':
				case '-':
				case '_':
					break;
				default:
					if ((list.get(i) >= 'a' && list.get(i) <= 'z') || (list.get(i) >= '0' && list.get(i) <= '9'))
						break;
					list.remove(i);
					i--;
					break;
				}
			}
		}

		if (list.size() != 0) {
			for (int i = 0; i < list.size() - 1; i++) {
				if (list.get(i) == '.' && list.size() >= 2) {
					while (true) {
						if (list.size() < i + 2 || list.get(i + 1) != '.')
							break;
						list.remove(i + 1);
					}
				}
			}
		}

		if (list.size() != 0) {
			if (list.get(0) == '.')
				list.remove(0);

			if (list.size() != 0) {
				if (list.get(list.size() - 1) == '.')
					list.remove(list.size() - 1);
			}
		}

		if (list.size() == 0) {
			list.add('a');
		}

		if (list.size() > 15) {
			while (true) {
				if (list.size() == 15)
					break;
				list.remove(15);
			}
			if (list.get(14) == '.')
				list.remove(14);
		}

		if (list.size() <= 2) {
			while (true) {
				if (list.size() == 3)
					break;
				list.add(list.get(list.size() - 1));
			}
		}

		StringBuilder answer = new StringBuilder();
		for (int i = 0; i < list.size(); i++) {
			answer.append(list.get(i));
		}

		return answer.toString();
	}
}