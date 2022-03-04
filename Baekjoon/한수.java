import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
		int n = s.nextInt();
        int han = 0;
        int cnt = 0;
        boolean check = false;

        if(n<100)
            han = n;
        else {
            String num;
            for(int i=100; i<=n; i++){
                num = Integer.toString(i);
                for(int j=0; j<num.length()-2; j++){
                    if(num.charAt(j)-num.charAt(j+1) == num.charAt(j+1)-num.charAt(j+2))
                        check = true;
                    else{
                        check = false;
                        break;
                    }
                }
                if(check)
                    cnt++;
            }
            han = 99+cnt;
        }
        
        System.out.println(han);
    }
}