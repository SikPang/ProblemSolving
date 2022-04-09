import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Queue<int[]> que = new LinkedList<>();
		String[] area = br.readLine().split(" ");
		String[][] map = new String[Integer.parseInt(area[1])][Integer.parseInt(area[0])];
		int[] index;
		int[] temp;
		int answer = 0;

		for (int i = 0; i < Integer.parseInt(area[1]); i++)
			map[i] = br.readLine().split(" ");

		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				if (map[i][j].equals("1")) {
					index = new int[3];
					index[0] = i;
					index[1] = j;
					index[2] = 0;
					que.offer(index);
				}
			}
		}

		while (!que.isEmpty()) {
			temp = new int[3];
			temp[0] = que.peek()[0];
			temp[1] = que.peek()[1];
			temp[2] = que.peek()[2];

			que.poll();

			if (temp[1] + 1 < map[0].length && map[temp[0]][temp[1] + 1].equals("0")) {
				index = new int[3];
				index[0] = temp[0];
				index[1] = temp[1] + 1;
				index[2] = temp[2]+1;
				que.offer(index);
				map[index[0]][index[1]] = "1";
			}

			if (temp[0] + 1 < map.length && map[temp[0] + 1][temp[1]].equals("0")) {
				index = new int[3];
				index[0] = temp[0] + 1;
				index[1] = temp[1];
				index[2] = temp[2]+1;
				que.offer(index);
				map[index[0]][index[1]] = "1";
			}

			if (temp[1] - 1 > -1 && map[temp[0]][temp[1] - 1].equals("0")) {
				index = new int[3];
				index[0] = temp[0];
				index[1] = temp[1] - 1;
				index[2] = temp[2]+1;
				que.offer(index);
				map[index[0]][index[1]] = "1";
			}

			if (temp[0] - 1 > -1 && map[temp[0] - 1][temp[1]].equals("0")) {
				index = new int[3];
				index[0] = temp[0] - 1;
				index[1] = temp[1];
				index[2] = temp[2]+1;
				que.offer(index);
				map[index[0]][index[1]] = "1";
			}

			if(answer < temp[2])
				answer = temp[2];
		}

		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				if (map[i][j].equals("0")) {
					bw.write("-1");
					bw.close();
					return;
				}
			}
		}
		bw.write(Integer.toString(answer));

		br.close();
		bw.close();
	}
}