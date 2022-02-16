public class Solution {
	public String solution(String s) {
        String answer = "";
		StringBuilder sb = new StringBuilder();
		boolean check = false;
		
		for(int i=0; i<s.length(); i++){
			if(i==0 || check){
				if(s.charAt(i)>='a' && s.charAt(i)<='z')
					sb.append((char) (s.charAt(i)-32));
				else
					sb.append(s.charAt(i));
				check = false;
			}
			else{
				if(s.charAt(i)>='A' && s.charAt(i)<='Z')
					sb.append((char) (s.charAt(i)+32));
				else
					sb.append(s.charAt(i));
			}

			if(s.charAt(i) == ' ')
				check = true;
		}
		
		answer = sb.toString();
        return answer;
    }
}