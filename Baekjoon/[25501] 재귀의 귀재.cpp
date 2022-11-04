#include <string.h>
#include <iostream>
using namespace std;

int recursion(const char *s, int l, int r, int *depth){
    ++(*depth);
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, depth);
}

int isPalindrome(const char *s, int *depth){
    return recursion(s, 0, strlen(s)-1, depth);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 0;
    cin >> tc;

    for(int i=0; i<tc; ++i)
    {
        char input[1001];
        int depth = 0;
        int result;

        cin >> input;
        result = isPalindrome(input, &depth);

        cout << result << ' ' << depth << '\n';
    }
}