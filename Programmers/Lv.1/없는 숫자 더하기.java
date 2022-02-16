import java.util.ArrayList;

public class Solution {
	public int solution(int[] numbers) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<>();

        for(int i=0; i<numbers.length; i++) {
        	list.add(numbers[i]);
        }
        
        for(int i=0; i<10; i++) {
        	if(!list.contains(i))
        		answer += i;
        }
        
        return answer;
    }
}