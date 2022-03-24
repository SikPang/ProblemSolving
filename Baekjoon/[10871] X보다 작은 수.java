import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int x = s.nextInt();
       
		for(int i=0; i<n; i++) {
			int number = s.nextInt();
    		if(number < x)
    			arr.add(number);
		}
		
		for(int i=0; i<arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
	}
}