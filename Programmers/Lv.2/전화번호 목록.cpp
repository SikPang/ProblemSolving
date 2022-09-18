#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool Compare(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else 
        return a < b;
}

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> map;

    sort(phone_book.begin(), phone_book.end(), Compare);

    int minLength = phone_book[0].length();

    for (int i = 0; i < phone_book.size(); ++i)
    {
        char str[21] = {};

        for (int j = 0; j < phone_book[i].length()-1; ++j)
        {
            str[j] = phone_book[i][j];

            if (j + 1 < minLength) continue;

            map[str] = true;
        }
    }

    for (int i = 0; i < phone_book.size(); ++i)
    {
        auto temp = map.find(phone_book[i]);
        if (map.find(phone_book[i]) != map.end())
            return false;
    }

    return true;
}