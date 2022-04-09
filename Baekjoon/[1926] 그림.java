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
		String[][] map = new String[Integer.parseInt(area[0])][Integer.parseInt(area[1])];
		int[] index;
		int[] temp;
		int answer = 0;
		int isAnswer = 0;
		int num = 0;

		for (int i = 0; i < Integer.parseInt(area[0]); i++)
			map[i] = br.readLine().split(" ");

		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				if (map[i][j].equals("2") || map[i][j].equals("0"))
					continue;

				if (que.isEmpty()) {
					index = new int[2];
					index[0] = i;
					index[1] = j;
					que.offer(index);
					num++;
					map[i][j] = "2";
				}

				isAnswer = 0;
				while (!que.isEmpty()) {
					temp = new int[2];
					temp[0] = que.peek()[0];
					temp[1] = que.peek()[1];

					que.poll();
					isAnswer++;

					if (temp[1] + 1 < map[0].length && map[temp[0]][temp[1] + 1].equals("1")) {
						index = new int[2];
						index[0] = temp[0];
						index[1] = temp[1]+1;
						que.offer(index);
						map[index[0]][index[1]] = "2";
					}

					if (temp[0] + 1 < map.length && map[temp[0] + 1][temp[1]].equals("1")) {
						index = new int[2];
						index[0] = temp[0]+1;
						index[1] = temp[1];
						que.offer(index);
						map[index[0]][index[1]] = "2";
					}

					if (temp[1] - 1 > -1 && map[temp[0]][temp[1] - 1].equals("1")) {
						index = new int[2];
						index[0] = temp[0];
						index[1] = temp[1]-1;
						que.offer(index);
						map[index[0]][index[1]] = "2";
					}

					if (temp[0] - 1 > -1 && map[temp[0] - 1][temp[1]].equals("1")) {
						index = new int[2];
						index[0] = temp[0]-1;
						index[1] = temp[1];
						que.offer(index);
						map[index[0]][index[1]] = "2";
					}
				}
				
				if(answer < isAnswer)
					answer = isAnswer;
			}
		}

		bw.write(Integer.toString(num) + "\n" + Integer.toString(answer));

		br.close();
		bw.close();
	}
}