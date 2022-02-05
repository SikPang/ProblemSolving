import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		ArrayList<Integer> value = new ArrayList<Integer>();
		
		for(int i=0; i<10; i++) {
			boolean isBreaked = false;
			int x = s.nextInt()%42;
			
			for(int j=0; j<value.size(); j++) {
				if(x == value.get(j)) {
					isBreaked = true;
					break;
				}
			}
			
			if(!isBreaked) {
				value.add(x);
			}
		}
		System.out.print(value.size());
	}
}