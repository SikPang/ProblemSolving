import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String word = br.readLine();
        int[] apb = new int[26];

        for(int i=0; i<word.length(); i++)
            apb[(int)word.charAt(i)-'a']++;
		
        for(int i=0; i<apb.length; i++)  
		    bw.write(Integer.toString(apb[i]) + " ");

        br.close();
		bw.close();
    }
}