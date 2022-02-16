import java.util.ArrayList;

class Solution {
    public long solution(long n) {
	        long answer = 0;
	        String s = Long.toString(n);
	        ArrayList<Integer> arr = new ArrayList<Integer>();
	        
	        for(int i=0; i<s.length(); i++) {
	        	arr.add(Character.getNumericValue(s.charAt(i)));
	        }
	        
	        for(int j=0; j<arr.size()-1; j++) {
	        	for(int i=0; i<arr.size()-1-j; i++) {
	        		if(arr.get(i) < arr.get(i+1)) {
	        			int temp = 0;
	        			temp = arr.get(i);
	        			arr.set(i, arr.get(i+1));
	        			arr.set(i+1, temp);
	        		}
	        	}
	        }
	        
	        s = "";
	        for(int i = 0; i<arr.size(); i++) {
	        	s += arr.get(i);
	        }
	        answer = Long.parseLong(s);
	        
	        return answer;
	 }
}