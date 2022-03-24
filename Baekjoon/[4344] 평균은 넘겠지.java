import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int c = s.nextInt();
		String[] avgs = new String[c];
		
		for(int i=0; i<c; i++) {
			int n = s.nextInt();
			int[] score = new int[n];
			int sum = 0;
			int cnt = 0;
			
			for(int j=0; j<n; j++) {
				score[j] = s.nextInt();
				sum += score[j];
			}
			double avg = sum/n;
			
			for(int j=0; j<n; j++) {
				if(avg<score[j])
					cnt++;
			}
			avgs[i] = String.format("%,.3f", (double)cnt/n*100);
		}
		
		for(int i=0; i<c; i++) {
			System.out.println(avgs[i]+"%");
		}
	}
}