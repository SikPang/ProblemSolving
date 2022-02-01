import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int x = s.nextInt();
		int y = s.nextInt();
		
		if(y-45>=0) {
			y-=45;
		}
		else if(y-45<0 && x-1>=0) {
			x-=1;
			y= 60 + y-45;
		}
		else if(y-45<0 && x-1<0) {
			x=23;
			y= 60 + y-45;
		}
		System.out.print(x + " " + y);
	}
}