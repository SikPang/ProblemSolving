import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
       Scanner s = new Scanner(System.in);
       int T = s.nextInt();
       int[] answer = new int[T];
       
       for(int i=0; i<T; i++) {
    	   String string = s.next();
    	   int check = 0;
       
    	   for(int j=0; j<string.length(); j++) {
    		   if(string.charAt(j) == 'O') {
    			   if(j!=0 && string.charAt(j) == string.charAt(j-1)) {
    				   check++;
    			   }
    			   answer[i] = answer[i] + 1 + check;
    		   }
    		   else {
    			   check = 0;
    		   }
    	   }
       }
       
       for(int i=0; i<answer.length; i++) {
    	   System.out.println(answer[i]);
       }
	}
}