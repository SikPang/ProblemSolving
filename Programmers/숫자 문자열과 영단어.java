public class Solution {
	public int solution(String s) {
        StringBuilder sb = new StringBuilder();
        
        for(int i=0; i<s.length(); i++) {
        	if('0'<=s.charAt(i) && s.charAt(i)<='9')
        		sb.append(s.charAt(i));
        	else {
        		switch(s.charAt(i)) {
        		case 'z' :
        			sb.append(0);
        			i+=3;
        			break;
        		case 'o':
        			sb.append(1);
        			i+=2;
        			break;
        		case 't':
        			if(s.charAt(i+1)=='w') {
        				sb.append(2);
        				i+=2;
        			}
        			else {
        				sb.append(3);
        				i+=4;
        			}
        			break;
        		case 'f':
        			if(s.charAt(i+1)=='o')
        				sb.append(4);
        			else
        				sb.append(5);
        			i+=3;
        			break;
        		case 's':
        			if(s.charAt(i+1)=='i') {
        				sb.append(6);
        				i+=2;
        			}
        			else {
        				sb.append(7);
        				i+=4;
        			}
        			break;
        		case 'e' :
        			sb.append(8);
        			i+=4;
        			break;
        		case 'n':
        			sb.append(9);
        			i+=3;
        			break;
        		}
        	}
        }
        return Integer.parseInt(sb.toString());
    }
}