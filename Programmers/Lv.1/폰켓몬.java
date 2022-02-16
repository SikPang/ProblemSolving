import java.util.ArrayList;

public class Solution {
	public int solution(int[] nums) {
        ArrayList<Integer> selected = new ArrayList<Integer>();
        
        for(int i=0; i<nums.length; i++) {
        	if(selected.size()==nums.length/2)
        		break;
        	if(!selected.contains(nums[i]))
        		selected.add(nums[i]);
        }
        
        return selected.size();
    }
}