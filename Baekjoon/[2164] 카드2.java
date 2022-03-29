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
        Queue<Integer> que = new LinkedList<>();
        int n = Integer.parseInt(br.readLine());
        
        for(int i=1; i<=n; i++)
            que.offer(i);

        int cnt = 1;
        while(que.size() > 1){
            if(cnt%2 == 1)
                que.poll();
            else{
                int temp = que.peek();
                que.poll();
                que.offer(temp);
            }
            cnt++;
        }

        bw.write(Integer.toString(que.peek()));
        
        br.close();
        bw.close();
    }
}