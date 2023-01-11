int way[60001];

int solution(int n) {

	way[1] = 1;
	way[2] = 2;
	for (int i = 3; i <= n; ++i)
		way[i] = (way[i - 1] + way[i - 2]) % 1000000007;

	return way[n];
}