import java.util.ArrayList;
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
        ArrayList<String> symbol = new ArrayList<>();
        int sequence = 1;
        int temp = Integer.parseInt(br.readLine());
        
        for(int i=0; i<temp; i++){
            int value = Integer.parseInt(br.readLine());

            if(stack.size()==0 || stack.peek() < value){
                while(true){
                    if(stack.size()!=0 && stack.peek()==value) break;
                    if(sequence > value){
                            bw.write("NO");
                            br.close();
                            bw.close();
                            return;
                    }
                    stack.push(sequence);
                    symbol.add("+");
                    sequence++;
                }
            }
            else if(stack.size()!=0 && stack.peek() > value){
                while(stack.peek() > value){
                    stack.pop();
                    symbol.add("-");
                }
            }
            stack.pop();
            symbol.add("-");
        }
        
        for(int i=0; i<symbol.size(); i++)
            bw.write(symbol.get(i) + "\n");
        br.close();
        bw.close();
    }
}