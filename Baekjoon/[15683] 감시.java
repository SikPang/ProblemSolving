import java.util.ArrayList;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static ArrayList<int[]> list = new ArrayList<>();
	static String[][] map;
	static String[][] tempMap;
	static int[][] cctv;
	static int[] isUsing;
	static int min = 64;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		map = new String[Integer.parseInt(input[0])][Integer.parseInt(input[1])];
		tempMap = new String[Integer.parseInt(input[0])][Integer.parseInt(input[1])];

		// 맵 채우기
		for (int i = 0; i < map.length; i++)
			map[i] = br.readLine().split(" ");

		// 맵 전체를 탐색하며 cctv가 있는 곳의 좌표와 번호를 list에 추가
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				if (!map[i][j].equals("0") && !map[i][j].equals("6"))
					list.add(new int[] { i, j, Integer.parseInt(map[i][j]) });
			}
		}

		// cctv 번호마다 감시 방향 배열 할당 (isUsed 겸용)
		cctv = new int[list.size()][4];
		isUsing = new int[list.size()];
		for (int i = 0; i < list.size(); i++) {
			switch (list.get(i)[2]) {
				case 1:
				case 3:
				case 4:
					cctv[i] = new int[] { 0, 0, 0, 0 }; // 4방향
					break;
				case 2:
					cctv[i] = new int[] { 0, 0, 3, 3 }; // 2방향
					break;
				case 5:
					cctv[i] = new int[] { 0, 3, 3, 3 }; // 1방향
					break;
			}
		}

		// DFS 시작
		Search(0);

		bw.write(Integer.toString(min));

		br.close();
		bw.close();
	}

	// 들어가면서 isUsed 체크, 마지막 cctv까지 방향 결정 후 맵 채우기
	static void Search(int depth) {
		// 맵 채우고 최솟값 비교
		if (depth == list.size()) {
			FillCheck();
			return;
		}

		// DFS
		for (int j = 0; j < 4; j++) {
			if (cctv[depth][j] == 3) continue;

			isUsing[depth] = j;

			Search(depth + 1);
		}
	}

	// 맵 채우고 최솟값 비교
	static void FillCheck() {
		// map 복사본 생성
		for (int i = 0; i < map.length; i++)
			tempMap[i] = Arrays.copyOf(map[i], map[i].length);

		for (int i = 0; i < cctv.length; i++) {
			// 현재 각 cctv의 방향 체크
			switch (isUsing[i]) {
				case 0:
					// 이 cctv의 번호 체크
					switch (list.get(i)[2]) {
						// 1번 cctv의 첫번째 방향
						case 1:
							FillRight(i);
							break;
						// 2번 cctv의 첫번째 방향
						case 2:
							FillLeft(i);
							FillRight(i);
							break;
						// 3번 cctv의 첫번째 방향
						case 3:
							FillUp(i);
							FillRight(i);
							break;
						case 4:
							// 4번 cctv의 첫번째 방향
							FillUp(i);
							FillLeft(i);
							FillRight(i);
							break;
						case 5:
							// 5번 cctv의 첫번째 방향
							FillLeft(i);
							FillRight(i);
							FillUp(i);
							FillDown(i);
							break;
					}
					break;
				case 1:
					switch (list.get(i)[2]) {
						case 1:
							// 1번 cctv의 두번째 방향
							FillDown(i);
							break;
						case 2:
							FillUp(i);
							FillDown(i);
							break;
						case 3:
							FillRight(i);
							FillDown(i);
							break;
						case 4:
							FillUp(i);
							FillRight(i);
							FillDown(i);
							break;
					}
					break;
				case 2:
					switch (list.get(i)[2]) {
						case 1:
							FillLeft(i);
							break;
						case 3:
							FillLeft(i);
							FillDown(i);
							break;
						case 4:
							FillLeft(i);
							FillRight(i);
							FillDown(i);
							break;
					}
					break;
				case 3:
					switch (list.get(i)[2]) {
						case 1:
							FillUp(i);
							break;
						case 3:
							FillUp(i);
							FillLeft(i);
							break;
						case 4:
							FillUp(i);
							FillLeft(i);
							FillDown(i);
							break;
					}
					break;
			}
		}

		// 빈 공간 갯수 세기
		int tempCnt = 0;
		for (int i = 0; i < tempMap.length; i++) {
			for (int j = 0; j < tempMap[0].length; j++) {
				if (tempMap[i][j].equals("0")) tempCnt++;
			}
		}
		if (tempCnt < min) min = tempCnt;
	}

	static void FillLeft(int n) {
		int i = list.get(n)[0];
		int j = list.get(n)[1];

		for (int x = j; x >= 0; x--) {
			if (x == j) continue;
			if (map[i][x].equals("6")) break;

			tempMap[i][x] = "#";
		}
	}

	static void FillRight(int n) {
		int i = list.get(n)[0];
		int j = list.get(n)[1];

		for (int x = j; x < map[0].length; x++) {
			if (x == j) continue;
			if (map[i][x].equals("6")) break;

			tempMap[i][x] = "#";
		}
	}

	static void FillUp(int n) {
		int i = list.get(n)[0];
		int j = list.get(n)[1];

		for (int x = i; x >= 0; x--) {
			if (x == i) continue;
			if (map[x][j].equals("6")) break;

			tempMap[x][j] = "#";
		}
	}

	static void FillDown(int n) {
		int i = list.get(n)[0];
		int j = list.get(n)[1];

		for (int x = i; x < map.length; x++) {
			if (x == i) continue;
			if (map[x][j].equals("6")) break;

			tempMap[x][j] = "#";
		}
	}
}