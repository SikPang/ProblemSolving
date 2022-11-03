#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, bool> map;
    int n, m;
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;

        map.insert({input, true});
    }

    for (int i = 0; i < m; ++i)
    {
        string input;
        cin >> input;

        if (map[input] == true)
            ++cnt;
    }

    cout << cnt;
}