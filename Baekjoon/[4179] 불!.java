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
		Queue<int[]> jihoon = new LinkedList<>();
		Queue<int[]> fire = new LinkedList<>();
		String[] area = br.readLine().split(" ");
		String[] map = new String[Integer.parseInt(area[0])];
		int[][] visited = new int[Integer.parseInt(area[0])][Integer.parseInt(area[1])];
		int[] peek;
		int answer = 0;
		boolean isEscaped = false;

		for (int i = 0; i < Integer.parseInt(area[0]); i++)
			map[i] = br.readLine();

		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length(); j++) {
				if (map[i].charAt(j) == 'J') {
					jihoon.offer(new int[] {i, j, 0});
					visited[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length(); j++) {
				if (map[i].charAt(j) == 'F') {
					fire.offer(new int[] {i, j, 0});
					visited[i][j] = 2;
				}
			}
		}

		int level = 0;
		while (!jihoon.isEmpty()) {
			if (jihoon.peek()[2] == level) {
				peek = new int[3];
				peek[0] = jihoon.peek()[0];
				peek[1] = jihoon.peek()[1];
				peek[2] = jihoon.peek()[2];

				jihoon.poll();

				if (visited[peek[0]][peek[1]] != 1)
					continue;

				visited[peek[0]][peek[1]] = 3;

				if ((peek[1] + 1 >= map[0].length() || peek[0] + 1 >= map.length || peek[1] - 1 <= -1|| peek[0] - 1 <= -1)) {
					answer = peek[2] + 1;
					isEscaped = true;
					break;
				}

				if (peek[1] + 1 < map[0].length() && map[peek[0]].charAt(peek[1] + 1) == '.' && visited[peek[0]][peek[1] + 1] == 0) {
					jihoon.offer(new int[] {peek[0], peek[1] + 1, peek[2] + 1});
					visited[peek[0]][peek[1] + 1] = 1;
				}

				if (peek[0] + 1 < map.length && map[peek[0] + 1].charAt(peek[1]) == '.'&& visited[peek[0] + 1][peek[1]] == 0) {
					jihoon.offer(new int[] {peek[0]+1, peek[1], peek[2] + 1});
					visited[peek[0]+1][peek[1]] = 1;
				}

				if (peek[1] - 1 > -1 && map[peek[0]].charAt(peek[1] - 1) == '.'&& visited[peek[0]][peek[1] - 1] == 0) {
					jihoon.offer(new int[] {peek[0], peek[1] - 1, peek[2] + 1});
					visited[peek[0]][peek[1]-1] = 1;
				}

				if (peek[0] - 1 > -1 && map[peek[0] - 1].charAt(peek[1]) == '.'&& visited[peek[0] - 1][peek[1]] == 0) {
					jihoon.offer(new int[] {peek[0]-1, peek[1], peek[2] + 1});
					visited[peek[0]-1][peek[1]] = 1;
				}
			} 
			else if (!fire.isEmpty() && fire.peek()[2] == level) {
				peek = new int[3];
				peek[0] = fire.peek()[0];
				peek[1] = fire.peek()[1];
				peek[2] = fire.peek()[2];

				fire.poll();

				visited[peek[0]][peek[1]] = 3;

				if (peek[1] + 1 < map[0].length() && map[peek[0]].charAt(peek[1] + 1) == '.' && (visited[peek[0]][peek[1] + 1] == 0 || visited[peek[0]][peek[1] + 1] == 1)) {
					fire.offer(new int[] {peek[0], peek[1] + 1, peek[2] + 1});
					visited[peek[0]][peek[1]+1] = 2;
				}

				if (peek[0] + 1 < map.length && map[peek[0] + 1].charAt(peek[1]) == '.' && (visited[peek[0] + 1][peek[1]] == 0 || visited[peek[0] + 1][peek[1]] == 1)) {
					fire.offer(new int[] {peek[0]+1, peek[1], peek[2] + 1});
					visited[peek[0]+1][peek[1]] = 2;
				}

				if (peek[1] - 1 > -1 && map[peek[0]].charAt(peek[1] - 1) == '.' && (visited[peek[0]][peek[1] - 1] == 0 || visited[peek[0]][peek[1] - 1] == 1)) {
					fire.offer(new int[] {peek[0], peek[1] - 1, peek[2] + 1});
					visited[peek[0]][peek[1]-1] = 2;
				}

				if (peek[0] - 1 > -1 && map[peek[0] - 1].charAt(peek[1]) == '.' && (visited[peek[0] - 1][peek[1]] == 0 || visited[peek[0] - 1][peek[1]] == 1)) {
					fire.offer(new int[] {peek[0]-1, peek[1], peek[2] + 1});
					visited[peek[0]-1][peek[1]] = 2;
				}
			} else
				level++;
		}

		if (isEscaped)
			bw.write(Integer.toString(answer));
		else
			bw.write("IMPOSSIBLE");

		br.close();
		bw.close();
	}
}