import java.util.ArrayList;

public class Solution {
	public String[] solution(String[] strings, int n) {
		String[] answer = new String[strings.length];

		for(int j=0; j<strings.length-1; j++) {
			for(int i=0; i<strings.length-1; i++) {
				if(strings[i].charAt(n) > strings[i+1].charAt(n)) {
					String temp = strings[i];
					strings[i] = strings[i+1];
					strings[i+1] = temp;
				}
				else if(strings[i].charAt(n) == strings[i+1].charAt(n)) {
					for(int k=0; k<strings[i].length(); k++) {
						if(strings[i].charAt(k) > strings[i+1].charAt(k)) {
							String temp = strings[i];
							strings[i] = strings[i+1];
							strings[i+1] = temp;
							break;
						}
						else if(strings[i].charAt(k) < strings[i+1].charAt(k)) 
							break;
					}
					
				}
			}
		}
		return strings;
	}
}
