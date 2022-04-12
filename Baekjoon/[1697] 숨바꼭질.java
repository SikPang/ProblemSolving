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
		boolean[] map;
		if(Integer.parseInt(area[1]) >= Integer.parseInt(area[0]))
			map = new boolean[(Integer.parseInt(area[1])+1)*2];
		else
			map = new boolean[(Integer.parseInt(area[0])+1)*2];
		int[] temp = {Integer.parseInt(area[0]), 0};
		int[] pos;

		que.offer(temp);
		map[Integer.parseInt(area[0])] = true;

		while(que.peek()[0] != Integer.parseInt(area[1])){
			temp = new int[2];
			temp[0] = que.peek()[0];
			temp[1] = que.peek()[1];
			que.poll();

			if (temp[0] + 1 < map.length && map[temp[0]+1]==false) {
				pos = new int[2];
				pos[0] = temp[0] + 1;
				pos[1] = temp[1] + 1;
				que.offer(pos);
				map[temp[0]] = true;
			}

			if (temp[0] - 1 > -1 && map[temp[0]-1]==false) {
				pos = new int[2];
				pos[0] = temp[0] - 1;
				pos[1] = temp[1] + 1;
				que.offer(pos);
				map[temp[0]] = true;
			}

			if (temp[0] * 2 < map.length && map[temp[0] * 2]==false) {
				pos = new int[2];
				pos[0] = temp[0] * 2;
				pos[1] = temp[1] + 1;
				que.offer(pos);
				map[temp[0]] = true;
			}
		}

		bw.write(Integer.toString(que.peek()[1]));

		br.close();
		bw.close();
	}
}