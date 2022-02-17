import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int hour = sc.nextInt();
        int minute = sc.nextInt();
        int timer = sc.nextInt();
        int plusHour = 0;

        minute += timer;
        if(minute>=60){
            plusHour = minute/60;
            minute%=60;
        }

        hour += plusHour;
        if(hour>=24){
            hour%=24;
        }

        System.out.println(hour + " " + minute);
    }
}