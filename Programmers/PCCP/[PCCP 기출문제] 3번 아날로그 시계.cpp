// 한 바퀴를 돌 때 까지
// 시침 : 43200초
// 분침 : 3600초
// 초침 : 60초

// 한 바퀴를 43200m라고 하면
// 시침 : 1초에 1m
// 분침 : 1초에 43200/3600 = 12m
// 초침 : 1초에 43200/60 = 720m

// 0h 0m 0s에서 시작 지점까지 돌리기
// 시작 지점에서 마지막까지 돌리기

#include <vector>
#define LIMIT 43200
#define HOUR_STEP 1
#define MIN_STEP 12
#define SEC_STEP 720

using namespace std;

int tiktok(int& h1, int& m1, int& s1, int start, int end, bool isCountable)
{
	int answer = 0;
	
	for (int i=start; i<end; ++i)
	{
		if (isCountable)
		{
			if (s1 <= h1 && s1 + SEC_STEP > h1 + HOUR_STEP)
				++answer;
			if (s1 <= m1 && s1 + SEC_STEP > m1 + MIN_STEP && h1 != m1)
				++answer;
		}
		
		h1 = (h1 + HOUR_STEP >= LIMIT ? 0 : h1 + HOUR_STEP);
        m1 = (m1 + MIN_STEP >= LIMIT ? 0 : m1 + MIN_STEP);
        s1 = (s1 + SEC_STEP >= LIMIT ? 0 : s1 + SEC_STEP);
	}
	if (isCountable && (s1 == h1) || (s1 == m1))
		++answer;
	return answer;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
	int curH = 0, curM = 0, curS = 0;
	int start = h1 * 3600 + m1 * 60 + s1;
	int end = h2 * 3600 + m2 * 60 + s2;

	tiktok(curH, curM, curS, 0, start, false);
	return tiktok(curH, curM, curS, start, end, true);
}
