import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
        HashMap<String, Boolean> map = new HashMap<>();
		String num = br.readLine();
        String[] nums = br.readLine().split(" ");
        String limit = br.readLine();
        int cnt = 0;

        for(int i=0; i<nums.length; i++){
            if(map.containsKey(Integer.toString(Integer.parseInt(limit)-Integer.parseInt(nums[i]))))
                cnt++;
            map.put(nums[i], true);
        }
		
		bw.write(Integer.toString(cnt));

        br.close();
		bw.close();
    }
}