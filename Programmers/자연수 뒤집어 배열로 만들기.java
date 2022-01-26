import java.util.ArrayList;

public class Solution {
	public ArrayList<Integer> solution(long n) {
	      String s = Long.toString(n);
	      ArrayList<Integer> arr = new ArrayList<Integer>();
	      
	      for(int i=s.length()-1; i>=0; i--) {
	    	  arr.add(Character.getNumericValue(s.charAt(i)));
	      }
	      
	      return arr;
	}
}