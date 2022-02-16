class Solution {
   public boolean solution(int x) {
        boolean answer = false;
        String s = "";
        int value = 0;
        
        s =  Integer.toString(x);
        
        for(int i=0; i<s.length(); i++) {
        	value += Character.getNumericValue(s.charAt(i));
        }
        
        if(x % value == 0)
        	answer = true;
        
        return answer;
    }
}