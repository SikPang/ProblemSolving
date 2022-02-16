class Solution {
    public String solution(String s, int n) {
        String answer = "";
        StringBuffer sb = new StringBuffer(s);
        
        for(int i=0; i<s.length(); i++) {
        	if(s.charAt(i) == (' ')) continue;
        	int cnt = 1;
        	
        	while(true) {
        		if(cnt>n) break;
        		
	        	if(s.charAt(i) == 'z' || s.charAt(i) == 'Z') {
	        		int temp = s.charAt(i);
		    		sb.deleteCharAt(i);
		    		sb.insert(i, (char)(temp-=25));
		    		s=sb.toString();
	        	}
	        	else {
		        	int temp = s.charAt(i);
		    		sb.deleteCharAt(i);
		    		sb.insert(i, (char)(temp+=1));
		    		s=sb.toString();
	        	}
	        	cnt++;
        	}
        }
        answer = sb.toString();
        
        return answer;
    }
}