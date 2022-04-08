import java.util.Stack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Stack<Character> stack;
		String str;
		boolean isBreaked;

		while (true) {
			str = br.readLine();
			if (str.equals(".")) break;
			stack = new Stack<>();
			isBreaked = false;

			for (int i = 0; i < str.length(); i++) {
				switch (str.charAt(i)) {
					case '(':
					case '[':
						stack.push(str.charAt(i));
						break;
					case ')':
						if (!stack.empty() && stack.peek() == '(')
							stack.pop();
						else {
							isBreaked = true;
							break;
						}
						break;
					case ']':
						if (!stack.empty() && stack.peek() == '[')
							stack.pop();
						else {
							isBreaked = true;
							break;
						}
						break;
					default:
						continue;
				}
				if (isBreaked) {
					bw.write("no" + "\n");
					break;
				}
			}
			if (!isBreaked) {
				if (stack.empty())
					bw.write("yes" + "\n");
				else
					bw.write("no" + "\n");
			}
		}

		bw.close();
		br.close();
	}
}