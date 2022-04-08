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
		int answer = 0;
		int n = Integer.parseInt(br.readLine());

		for (int i=0; i<n; i++) {
			str = br.readLine();
			stack = new Stack<>();

			for (int j = 0; j < str.length(); j++) {
				switch (str.charAt(j)) {
					case 'A':
						if (!stack.empty() && stack.peek() == 'A')
							stack.pop();
						else
							stack.push('A');
						break;
					case 'B':
						if (!stack.empty() && stack.peek() == 'B')
							stack.pop();
						else
							stack.push('B');
						break;
					default:
						continue;
				}
			}
			if (stack.empty())
				answer++;
		}
		bw.write(Integer.toString(answer));

		bw.close();
		br.close();
	}
}