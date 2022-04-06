import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		String[] deque = new String[n*2];
		int head = n;
		int tail = n-1;
		
		for(int i=0; i<n; i++){
			String[] strs = br.readLine().split(" ");
			
			if(strs[0].equals("push_front")){
				deque[head] = strs[1];
				head++;
			}
			else if(strs[0].equals("push_back")){
				deque[tail] = strs[1];
				tail--;
			}
			else if(strs[0].equals("pop_front")){
				if(deque[head-1] != null){
					bw.write(deque[head-1] + "\n");
					deque[head-1] = null;
					head--;
				}
				else
					bw.write("-1" + "\n");
			}
			else if(strs[0].equals("pop_back")){
				if(deque[tail+1] != null){
					bw.write(deque[tail+1] + "\n");
					deque[tail+1] = null;
					tail++;
				}
				else
					bw.write("-1" + "\n");
			}
			else if(strs[0].equals("size")){
				bw.write(head-tail-1 + "\n");
			}
			else if(strs[0].equals("empty")){
				if(head-tail-1 == 0)
					bw.write("1" + "\n");
				else
					bw.write("0" + "\n");
			}
			else if(strs[0].equals("front")){
				if(deque[head-1] != null)
					bw.write(deque[head-1] + "\n");
				else
					bw.write("-1" + "\n");
			}
			else if(strs[0].equals("back")){
				if(deque[tail+1] != null)
					bw.write(deque[tail+1] + "\n");
				else
					bw.write("-1" + "\n");
			}
		}

		bw.close();
		br.close();
	}
}