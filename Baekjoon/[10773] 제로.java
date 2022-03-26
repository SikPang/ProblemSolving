import java.util.Stack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<String> stack = new Stack<>();
        int answer = 0;
        String temp = br.readLine();
        
        for(int i=0; i<Integer.parseInt(temp); i++){
            String value = br.readLine();

            if(value.equals("0") && !stack.isEmpty())
                stack.pop();
            else
                stack.push(value);
        }

        while(!stack.isEmpty()){
            answer += Integer.parseInt(stack.peek());
            stack.pop();
        }

        bw.write(Integer.toString(answer));

        br.close();
        bw.close();
    }
}