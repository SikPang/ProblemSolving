class Solution {
    public String solution(String s) {
        String answer = "";
        
        if(s.length()%2==0) {	// 단어의 길이 짝수
        	answer += s.charAt(s.length()/2-1);
        	answer += s.charAt(s.length()/2);
        }
        else {
        	answer += s.charAt((int)s.length()/2);
        }
        
        return answer;
    }
}