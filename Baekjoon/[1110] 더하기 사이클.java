import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int input = s.nextInt();
		String string = Integer.toString(input);
		if(input<10)
			string+=0;
		
		int a = Character.getNumericValue(string.charAt(0));
		int b = Character.getNumericValue(string.charAt(1));
		int aTemp = a;
		int bTemp = b;
		int cnt = 0;
		
		while(true) {
			int temp = a;
			a = b;
			b = temp + b;
			if(b>9) 
			{
				string = Integer.toString(b);
				b = Character.getNumericValue(string.charAt(1));
			}
			cnt++;
			if(a==aTemp && b == bTemp) break;
		}
		
		System.out.print(cnt);
	}
}