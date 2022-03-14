import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        int answer = Fibonacci(0, 1, 0, n);

        System.out.println(answer);
    }

    private static int Fibonacci(int prev2, int prev1, int turn, int max){
        if(max == turn) return prev2;

        int temp = prev1;
        prev1 = prev1 + prev2;
        prev2 = temp;

        turn++;

        return Fibonacci(prev2, prev1, turn, max);
    }
}