import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
    	ArrayList<Integer> list = new ArrayList<Integer>();
    	
    	for(int i=1; i<=10000; i++) {
    		String s = Integer.toString(i);
    		int number=i;
    		for(int j=0; j<s.length(); j++) {
    			number += Character.getNumericValue(s.charAt(j));
    		}
    		list.add(number);
    	}
    	
    	for(int i=1; i<=10000; i++) {
    		if(list.contains(i))
    			continue;
    		System.out.println(i);
    	}
    }
}