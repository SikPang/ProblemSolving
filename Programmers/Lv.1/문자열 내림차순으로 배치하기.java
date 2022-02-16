class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuilder sb = new StringBuilder(s);
        
        for(int i=0; i<s.length()-1; i++) {
        	for(int j=0; j<s.length()-1; j++) {
        		if(sb.charAt(j) < sb.charAt(j+1)) {
        			char temp = sb.charAt(j);
        			sb.setCharAt(j, sb.charAt(j+1));
        			sb.setCharAt(j+1, temp);
        		}
        	}
        }
        answer = sb.toString();
        return answer;
    }
}