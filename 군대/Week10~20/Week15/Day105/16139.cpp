#include <iostream>

using namespace std;

int ac[200001][26];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++) // 각 알파벳의 누적 합을 구해야 함
    {
        int cur = str[i] - 'a';
        for(int j = 0; j < 26; j++)
        {
            if(j == cur)
                ac[i+1][j] = ac[i][j] + 1;
            else
                ac[i+1][j] = ac[i][j];
        }
    }
    int testcase;
    cin >> testcase;
    char ch;
    int s, e;
    while(testcase--)
    {
        cin >> ch >> s >> e;
        cout << ac[e+1][ch - 'a'] - ac[s][ch - 'a'] << '\n'; 
    }
}