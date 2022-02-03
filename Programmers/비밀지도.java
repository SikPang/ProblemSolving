import java.util.ArrayList;

public class Solution {
	public String[] solution(int n, int[] arr1, int[] arr2) {
		String[] answer = new String[n];
		
		for (int i = 0; i < arr1.length; i++) {
			String binaryString = Integer.toBinaryString(arr1[i] | arr2[i]);
			ArrayList<String> list = new ArrayList<String>();
			
			for (int j = 0; j < binaryString.length(); j++) {
				switch (binaryString.charAt(j)) {
				case '1':
					list.add("#");
					break;
				case '0':
					list.add(" ");
					break;
				}
			}
			
			while(true) {
				if(list.size() == n) break;
				list.add(0," ");
			}
			
			answer[i]= list.get(0);
			for(int j=1; j<list.size(); j++) {
				answer[i] += list.get(j);
			}
		}
		return answer;
	}
}
