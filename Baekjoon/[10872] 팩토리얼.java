import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int answer = 1;

        answer = Factorial(n, answer);

        System.out.println(answer);
    }

    private static int Factorial(int num, int value){
        if(num <= 1) return value;

        value*=num;
        num--;

        return Factorial(num, value);
    }
}