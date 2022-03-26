import java.util.HashMap;
import java.util.Stack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Integer> stack = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        String temp = br.readLine();
        String[] num = br.readLine().split(" "); 
        int[] answer = new int[num.length];

        for(int i=0; i<num.length; i++)
            map.put(Integer.parseInt(num[i]), i);

        for(int i=num.length-1; i>=0; i--){
            if(stack.size()!=0 && stack.peek() < Integer.parseInt(num[i])){
                while(true){
                    answer[map.get(stack.peek())] = i+1;  // 인덱스
                    stack.pop();
                    if(stack.size()==0 || stack.peek() > Integer.parseInt(num[i])) break;
                }
            }
            stack.push(Integer.parseInt(num[i]));
        }

        for(int i=0; i<answer.length; i++)
            bw.write(Integer.toString(answer[i]) + " ");

        br.close();
        bw.close();
    }
}