import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static ArrayList<int[]> house = new ArrayList<>();
	static ArrayList<int[]> chicken = new ArrayList<>();
	static boolean[] isUsed;
	static String[][] map;
	static int answer=Integer.MAX_VALUE;
	static int max;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		map = new String[Integer.parseInt(input[0])][Integer.parseInt(input[0])];
		max = Integer.parseInt(input[1]);

		// 맵 채우기
		for (int i = 0; i < map.length; i++)
			map[i] = br.readLine().split(" ");

		// 집, 치킨집 리스트에 넣기
		for (int i = 0; i < map.length; i++){
			for (int j = 0; j < map.length; j++){
				if(map[i][j].equals("2")) chicken.add(new int[] { i, j});
				else if(map[i][j].equals("1")) house.add(new int[] { i, j});
			}
		}
		isUsed = new boolean[chicken.size()];

		// 백트래킹 시작
		Tracking(0, 0);

		bw.write(Integer.toString(answer));

		br.close();
		bw.close();
	}

	static void Tracking(int depth, int index){
		if(depth == max){
			Distance();
			return;	
		}

		for(int i=index; i<chicken.size(); i++){
			if(isUsed[i]) continue;

			isUsed[i] = true;
			Tracking(depth+1, i+1);
			isUsed[i] = false;
		}
	}

	// 고른 치킨집 중에 최소 거리를 구하여 총 치킨거리를 구함
	static void Distance(){
		int sum = 0;
		for(int i=0; i<house.size(); i++){
			int min = Integer.MAX_VALUE;
			for(int j=0; j<isUsed.length; j++){
				if(!isUsed[j]) continue;
				min = Math.min(min, Math.abs(house.get(i)[0]-chicken.get(j)[0]) + Math.abs(house.get(i)[1]-chicken.get(j)[1]));
			}
			sum += min;
		}
		// 총 치킨거리가 지금까지 구한 최소 치킨거리보다 작으면 바꿈
		answer = Math.min(answer, sum);
	}
}