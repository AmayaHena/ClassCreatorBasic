#include <bits/stdc++.h>
using namespace std;

int countFreq(string &s, string &tag)
{
    int N = s.length();
    int M = tag.length();
    int match = 0;
    int j = 0;

    for (int i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++)
            if (s[i + j] != tag[j])
                break;
        if (j == M)
            match++;
    }
    return match;
}

int main()
{
    string s = "dhimanmanzhiaeiazma,zujhezhma";
    string tag = "ma";
    cout << countFreq(s, tag) << endl;

    int i = 0;
    for (int k = s.find("ma"); i < 4; i++) {
        cout << k << endl;
        k = s.find("ma", k + 1);
    }
    return 0;
}