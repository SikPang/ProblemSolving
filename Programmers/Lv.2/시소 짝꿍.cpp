#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
	unordered_map<double, unsigned long long> counter;
	
	for (int i = 0; i < weights.size(); ++i)
	{
		unsigned long long target = weights[i];
		if (counter.find(target) != counter.end())
			++counter[target];
		else
			counter.insert(make_pair(target, 1));
	}

	for (unordered_map<double, unsigned long long>::iterator iter = counter.begin(); iter != counter.end(); ++iter)
	{
		answer += iter->second * (iter->second - 1) / 2;
        
        double target = iter->first / 2;
		if (counter.find(target) != counter.end())
			answer += counter[iter->first] * counter[target];
        
        target = iter->first * 3.0 / 2.0;
		if (counter.find(target) != counter.end())
			answer += counter[iter->first] * counter[target];
        
        target = iter->first * 4.0 / 3.0;
		if (counter.find(target) != counter.end())
			answer += counter[iter->first] * counter[target];
	}
    return answer;
}

// n개 중에 r개를 선택할 때, 조합 경우의 수 nCr = nPr / r!
// n개 중에 r개를 선택할 때, 순열 경우의 수 nPr = n! / (n - r)!

// ----- r이 2라면
// nC2 = nP2 / 2!
// nP2 = n! / (n - 2)!

// ----- n! / (n - 2)! 간단히
// n!		= n * (n - 1) * (n - 2) * (n - 3) ...
// (n - 2)!	= 				(n - 2) * (n - 3) ...

// ----- 결론
// nP2		= n * (n - 1)
// nC2		= n * (n - 1) / 2

// ----- 로직
// 몸무게를 key로 가지고, 인원을 value로 가지는 counter 생성
// 현재 몸무게를 *2, *3/2, *4/3 연산한 몸무게를 counter에서 찾음
// 현재 순회 몸무게가 3명이고 counter에서 찾은 몸무게가 2명이 있다면 짝꿍은 6쌍 나오므로 answer += 6
// 본인과 같은 몸무게 인원이 짝을 이룰 수 있는 경우의 수 