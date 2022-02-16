class Solution {
    boolean solution(String s) {
        int yCnt = 0;
        int pCnt = 0;

        for(int i=0; i<s.length(); i++) {
        	if(s.charAt(i) == 'y' || s.charAt(i) == 'Y' )
        		yCnt++;
        	else if(s.charAt(i) == 'p' || s.charAt(i) == 'P' )
        		pCnt++;
        }
        if(yCnt==pCnt)
        	return true;
        else
        	return false;
    }
}