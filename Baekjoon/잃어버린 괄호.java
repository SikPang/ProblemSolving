import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        ArrayList<Long> numberList = new ArrayList<>();
        ArrayList<Character> symbolList = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                sb.append(s.charAt(i));
            } else {
                numberList.add(Long.parseLong(sb.toString()));
                symbolList.add(s.charAt(i));
                sb = new StringBuilder();
            }
        }
        numberList.add(Long.parseLong(sb.toString()));
        
        int i=0;
        while(true){
            if(!symbolList.contains('+')) break;
            if (symbolList.get(i) == '+') {
                numberList.set(i, numberList.get(i) + numberList.get(i + 1));
                numberList.remove(i + 1);
                symbolList.remove(i);
                i--;
            }
            i++;
        }
        
        while (true) {
            if (symbolList.size() == 0) break;
            numberList.set(0, numberList.get(0) - numberList.get(1));
            numberList.remove(1);
            symbolList.remove(0);
        }
        System.out.println(numberList.get(0));
    }
}