import java.util.Stack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Stack<Character> stack = new Stack<>();
		String str = br.readLine();
		int answer = 0;

		for(int i=0; i<str.length(); i++){
			switch(str.charAt(i)){
				case '(':
					stack.push('-');
					break;
				case ')':
					stack.pop();
					if(str.charAt(i-1) == '(')
						answer += stack.size();
					else
						answer++;
					break;
			}
		}
		bw.write(Integer.toString(answer));

		bw.close();
		br.close();
	}
}