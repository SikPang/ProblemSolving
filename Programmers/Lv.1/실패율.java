// N = 전체 (스테이지 개수)
// stages[] = 유저가 도전 중인 (스테이지 번호)
// answer[] = 실패율이 높은 스테이지 내림차순 (스테이지 번호)
// 실패율 = 도전 중인 유저 수 / 클리어 한 유저 수
// 도달한 유저 없을 시 해당 스테이지의 실패율 = 0

public class Solution {
	public int[] solution(int N, int[] stages) {
		int[] answer = new int[N];
		double[] fail = new double[N];	// 인덱스 = 스테이지 번호 (각 스테이지의 실패율)
		int[] trying = new int[N+1];	// 인덱스 = 스테이지 번호 (도전 중인 유저의 수)
		int[] cleared = new int[N+1];	// 인덱스 = 스테이지 번호 (도달한 유저의 수)
		
		for(int i=0; i<N; i++) {				// 스테이지 번호 채우기
			answer[i] = i+1;
		}
		
		for (int i = 0; i < stages.length; i++) { // 모든 유저 검사
			trying[stages[i]-1]++;
			for(int j=0; j<stages[i]; j++) {
				cleared[j]++;
			}
		}
		
		for (int i = 0; i < N; i++) {			// 실패율 계산
			fail[i] = (double)trying[i]/(double)cleared[i];
		}
		
		for(int i=0; i<N; i++) {				// 정렬
			for(int j=0; j<N-1; j++) {
				if(fail[j] < fail[j+1]) {
					double temp = fail[j];		// 실패율 정렬
					fail[j] = fail[j+1];
					fail[j+1] = temp;
					
					int temp2 = answer[j];		// 스테이지 같이 바꿔주기
					answer[j] = answer[j+1];
					answer[j+1] = temp2;
				}
			}
		}
		
		return answer;
	}
}