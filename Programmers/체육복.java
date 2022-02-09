public class Solution {
	public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] student = new int[n];
        
        for(int i=0; i<n; i++)	// i 채우기
        	student[i] = 1;
        
        for(int i=0; i<lost.length; i++)	// (인덱스 = 학생 번호) 안 가져온 학생 0으로 변경
        	student[lost[i]-1]--;
        
        for(int i=0; i<reserve.length; i++)	// (인덱스 = 학생 번호) 여벌옷 가져온 학생 2로 변경
        	student[reserve[i]-1]++;
        
        for(int i=0; i<n; i++) {	// 2인 학생 검사하여 좌우 탐색 후 빌려주기
        	if(student[i]==2) {
        		if(i!=0 && student[i-1]==0) {
        			student[i-1] = 1;
    				student[i] = 1;
        		}
        		else if (i!=n-1 && student[i+1]==0) {
        			student[i+1] = 1;
    				student[i] = 1;
        		}
        	}
        }
        
        for(int i=0; i<n; i++) {	// 1 이상인 학생 검사
        	if(student[i] >= 1)
        		answer++;
        }
        
        return answer;
    }
}