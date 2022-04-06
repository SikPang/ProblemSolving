import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] n = br.readLine().split(" ");
		String[] index = br.readLine().split(" ");
		ArrayList<Integer> que = new ArrayList<>();
		int answer = 0;
		int[] cnt;

		for (int i = 1; i <= Integer.parseInt(n[0]); i++)
			que.add(i);

		for (int i = 0; i < index.length; i++) {
			cnt = new int[2];
			for(int j=0; j<2; j++){
				int k = 0;
				while(que.get(k)!=Integer.parseInt(index[i])){
					if(j==0)
						k++;
					else{
						k--;
						if(k==-1) k=que.size()-1;
					}
					cnt[j]++;
				}
			}

			if (cnt[0] <= cnt[1]) {
				while (que.get(0) != Integer.parseInt(index[i])) {
					int temp = que.get(0);
					que.remove(0);
					que.add(temp);
					answer++;
				}
			} else if (cnt[0] > cnt[1]) {
				while (que.get(0) != Integer.parseInt(index[i])) {
					int temp = que.get(que.size() - 1);
					que.remove(que.size() - 1);
					que.add(0, temp);
					answer++;
				}
			}
			que.remove(0);
		}
		bw.write(Integer.toString(answer));

		bw.close();
		br.close();
	}
}