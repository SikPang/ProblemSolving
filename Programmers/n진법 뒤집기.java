import java.util.ArrayList;

public class Solution {     // n진법 뒤집기 (n<=10)
	public int solution(int n) {
        int answer = 0;
        int x = 3;
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        int i=0;
        while(true) {
        	if(n==0) break;
        	list.add(i, n % x);
        	n /= x;
        	
        	i++;
        }
        
        i=0;
        for(int j=list.size()-1; j>=0; j--) {
        	for(int k=0; k<list.get(j); k++) {
        		int value = 1;
        		for(int l=0; l<i; l++) {
        			value *= x;
        		}
        		answer += value;
        	}
        	i++;
        }
        
        return answer;
    }
}