import java.util.ArrayList;
import java.util.Comparator;

public class Solution {
	public  ArrayList<Integer> solution(int[] numbers) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        for(int i=0; i<numbers.length-1; i++) {
        	for(int j=i+1; j<numbers.length; j++) {
        		
        		if(!list.contains(numbers[i] + numbers[j]))
        			list.add(numbers[i] + numbers[j]);
        	}
        }
        
        list.sort(Comparator.naturalOrder());
        
        return list;
    }
}