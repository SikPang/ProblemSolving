import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static ArrayList<Integer> list = new ArrayList<>();
	static boolean[] isUsed;
	static int max;
	static int length;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] area = br.readLine().split(" ");
		max = Integer.parseInt(area[0]);
		length = Integer.parseInt(area[1]);
		isUsed = new boolean[max];

		NnM(0);

		br.close();
		bw.close();
	}

	static void NnM(int depth) throws IOException {
		if (depth == max) return;

		for (int i = 1; i <= max; i++) {
			if (isUsed[i-1]) continue;

			list.add(i);
			isUsed[i-1] = true;
			if (list.size() == length) {
				for (int j = 0; j < list.size(); j++) {
					bw.write(Integer.toString(list.get(j)) + " ");
				}
				bw.newLine();
			}

			if (list.size() < length)
				NnM(depth + 1);

			isUsed[list.get(list.size()-1)-1] = false;
			list.remove(list.size() - 1);
		}
	}
}