import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = br.readLine();

        int[] num = new int[10];
        int max = 0;
        
        for(int i=0; i<str.length(); i++)
            num[str.charAt(i)-'0']++;

        if(num[6] > num[9]){
            while(num[6]>num[9]){
                num[6]--;
                num[9]++;
            }
        }
        else if(num[9] > num[6]){
            while(num[9]>num[6]){
                num[6]++;
                num[9]--;
            }
        }

        for(int i=0; i<10; i++)
            if(max < num[i]) max = num[i];
		
		bw.write(Integer.toString(max));

        br.close();
		bw.close();
    }
}