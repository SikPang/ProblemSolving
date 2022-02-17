import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] won = new int[n];
        int answer = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            won[i] = sc.nextInt();
        }

        for (int i = n - 1; i >= 0; i--) {
            if (answer == k) break;
            if (won[i] > k) continue;

            if (answer + won[i] <= k) {
                answer += won[i];
                cnt++;
                i++;
            }
        }
        System.out.println(cnt);
    }
}