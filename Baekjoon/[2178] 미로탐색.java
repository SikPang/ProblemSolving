import java.util.LinkedList;
import java.util.Queue;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Queue<int[]> que = new LinkedList<>();
		String[] area = br.readLine().split(" ");
		String[] map = new String[Integer.parseInt(area[0])];
		boolean[][] visitCheck = new boolean[Integer.parseInt(area[0])][Integer.parseInt(area[1])];
		int[] pos = { 0, 0, 1};
		int[] temp;

		for (int i = 0; i < map.length; i++)
			map[i] = br.readLine();

		que.offer(pos);
		visitCheck[0][0] = true;

		while (que.peek()[0] != map.length - 1 || que.peek()[1] != map[0].length() - 1) {
			temp = new int[3];
			temp[0] = que.peek()[0];
			temp[1] = que.peek()[1];
			temp[2] = que.peek()[2];

			que.poll();

			if (temp[1] + 1 < map[0].length() && map[temp[0]].charAt(temp[1]+1)=='1' && visitCheck[temp[0]][temp[1]+1]==false) {
				pos = new int[3];
				pos[0] = temp[0];
				pos[1] = temp[1] + 1;
				pos[2] = temp[2] + 1;
				que.offer(pos);
				visitCheck[pos[0]][pos[1]] = true;
			}

			if (temp[0] + 1 < map.length && map[temp[0]+1].charAt(temp[1])=='1'  && visitCheck[temp[0]+1][temp[1]]==false) {
				pos = new int[3];
				pos[0] = temp[0] + 1;
				pos[1] = temp[1];
				pos[2] = temp[2] + 1;
				que.offer(pos);
				visitCheck[pos[0]][pos[1]] = true;
			}

			if (temp[1] - 1 > -1 && map[temp[0]].charAt(temp[1]-1)=='1'  && visitCheck[temp[0]][temp[1]-1]==false) {
				pos = new int[3];
				pos[0] = temp[0];
				pos[1] = temp[1] - 1;
				pos[2] = temp[2] + 1;
				que.offer(pos);
				visitCheck[pos[0]][pos[1]] = true;
			}

			if (temp[0] - 1 > -1 && map[temp[0]-1].charAt(temp[1])=='1' && visitCheck[temp[0]-1][temp[1]]==false) {
				pos = new int[3];
				pos[0] = temp[0] - 1;
				pos[1] = temp[1];
				pos[2] = temp[2] + 1;
				que.offer(pos);
				visitCheck[pos[0]][pos[1]] = true;
			}
		}

		bw.write(Integer.toString(que.peek()[2]));

		br.close();
		bw.close();
	}
}