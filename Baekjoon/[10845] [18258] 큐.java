import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] arr = new String[n];
        int head = 0;
        int tail = 0;
        
        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            if(str[0].equals("push")){
                arr[tail] = str[1];
                tail++;
            }
            else if(str[0].equals("pop")){
                if(head==tail) bw.write(-1 + "\n");
                else{
                    bw.write(arr[head] + "\n");
                    head++;
                }
            }
            else if(str[0].equals("size")){
                bw.write(tail-head + "\n");
            }
            else if(str[0].equals("empty")){
                if(head==tail) bw.write(1 + "\n");
                else bw.write(0 + "\n");
            }
            else if(str[0].equals("front")){
                if(head==tail) bw.write(-1 + "\n");
                else bw.write(arr[head] + "\n");
            }
            else if(str[0].equals("back")){
                if(head==tail) bw.write(-1 + "\n");
                else bw.write(arr[tail-1] + "\n");
            }
        }
        br.close();
        bw.close();
    }
}