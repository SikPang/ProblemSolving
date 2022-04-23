import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static ArrayList<Integer> list = new ArrayList<>();
	static boolean[] isUsed1;
	static boolean[] isUsed2;
	static boolean[] isUsed3;
	static int n;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		isUsed1 = new boolean[n];
		isUsed2 = new boolean[2*n-1];
		isUsed3 = new boolean[2*n-1];

		Queen(0);

		bw.write(Integer.toString(answer));

		br.close();
		bw.close();
	}

	static void Queen(int depth) {
		if(n==depth) {
			answer++;
			return;
		}

		for(int i=0; i<n; i++){
			if(isUsed1[i] || isUsed2[i+depth] || isUsed3[i-depth+n-1]) continue;

			isUsed1[i] = true;
			isUsed2[i+depth] = true;
			isUsed3[i-depth+n-1] = true;

			Queen(depth+1);

			isUsed1[i] = false;
			isUsed2[i+depth] = false;
			isUsed3[i-depth+n-1] = false;
		}
	}
}