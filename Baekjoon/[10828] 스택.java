import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] arr = new int[10001];
        int pos = 0;
		
        String temp = br.readLine();
        for(int i=0; i<Integer.parseInt(temp); i++){
        String[] string = br.readLine().split(" ");
            
            if(string[0].equals("push")){
                arr[pos] = Integer.parseInt(string[1]);
                pos++;
            }
            else if(string[0].equals("pop")){
                if(pos==0)
                    bw.write("-1"+"\n");
                else{
                    bw.write(Integer.toString(arr[pos-1])+"\n");
                    pos--;
                }
            }
            else if(string[0].equals("size")){
                bw.write(Integer.toString(pos)+"\n");
            }
            else if(string[0].equals("empty")){
                if(pos==0)
                    bw.write("1"+"\n");
                else
                    bw.write("0"+"\n");
            }
            else if(string[0].equals("top")){
                if(pos==0)
                    bw.write("-1"+"\n");
                else
                    bw.write(Integer.toString(arr[pos-1])+"\n");
            }
        }
        br.close();
        bw.close();
    }
}