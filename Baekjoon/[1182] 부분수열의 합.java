import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static ArrayList<String> list = new ArrayList<>();
	static int[] nums;
	static boolean[] isUsed;
	static int goal;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		String[] num = br.readLine().split(" ");

		goal = Integer.parseInt(input[1]);

		nums = new int[num.length];
		for (int i = 0; i < num.length; i++) {
			nums[i] = Integer.parseInt(num[i]);
		}
		isUsed = new boolean[num.length];

		Sum(0, 0);

		if(goal==0) answer--;
		bw.write(Integer.toString(answer));

		br.close();
		bw.close();
	}

	static void Sum(int depth, int sum) {
		if (depth == nums.length) {
			if (sum == goal)
				answer++;
			return;
		}

		Sum(depth + 1, sum);
		Sum(depth + 1, sum + nums[depth]);
	}
}