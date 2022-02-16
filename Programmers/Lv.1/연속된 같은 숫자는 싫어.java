import java.util.ArrayList;

public class Solution {
	public ArrayList<Integer> solution(int[] arr) {
		ArrayList<Integer> list = new ArrayList<Integer>();

		for (int i = 0; i < arr.length; i++) {
			if(i==0 || list.get(list.size()-1) != arr[i])
				list.add(arr[i]);
		}

		return list;
	}
}
