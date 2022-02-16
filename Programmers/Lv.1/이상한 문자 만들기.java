class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuffer sb = new StringBuffer(s);
        int j=0;
        
        for(int i=0; i<s.length(); i++) {
        	if(s.charAt(i) == (' ')) {
        		j=0;
        		continue;
        	}
        	if(j%2 == 0) {
	        	if(97<=s.charAt(i)) {	// 소문자
	        		int temp = s.charAt(i);
	        		sb.deleteCharAt(i);
	        		sb.insert(i, (char)(temp-=32));
	        	}
        	}
        	else {
        		if(s.charAt(i)<=90) {	// 대문자
	        		int temp = s.charAt(i);
	        		sb.deleteCharAt(i);
	        		sb.insert(i, (char)(temp+=32));
	        	}
        	}
        	j++;
        }
        answer = sb.toString();
        
        return answer;
    }
}