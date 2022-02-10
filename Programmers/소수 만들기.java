public class Solution {
	public int solution(int[] nums) {
        int answer = 0;

        for(int i=0; i<nums.length-2; i++) {
        	for(int j=i+1; j<nums.length-1; j++) {
        		for(int k=j+1; k<nums.length; k++) {
        			int value = nums[i]+nums[j]+nums[k];
        			int cnt=0;
        			for(int l=2; l*l<=value; l++) {
        				if(value%l==0) {
        					cnt++;
        					break;
        				}
        			}
                	if(cnt==0) answer++;
                }	
            }
        }

        return answer;
    }
}