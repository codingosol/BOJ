#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long int_64; // long long으로도 작음

int_64 small[101][101]; // 100까지의 연산결과 저장
int_64 big[101][101]; // 100까지의 연산결과 but 몫 저장

pair<int_64,int_64> hockeystick(int_64 first, int_64 second)
{
    if(small[first][second] == -1) // 방문한 적 없을 경우
    {
        if(first == second || second == 0)
        {
            return {0,1};
        }
        else {
            pair<int_64,int_64> res = {0,0};
            for(int_64 i = first - 1; i >= second - 1; i--)
            {
                pair<int_64,int_64> tmp = hockeystick(i, second - 1); // 단순재귀는 너무느려 100까지 연산결과를 저장하는건..?
                res.first += tmp.first;
                res.second += tmp.second;
                if(res.second > 10000000000000000)
                {
                    res.second %= 10000000000000000;
                    res.first += res.second / 10000000000000000;
                }
            }
            big[first][second] = res.first;
            small[first][second] = res.second % 10000000000000000;
            return res;
        }
    }
    else { // 방문한 적 있다면
        return {big[first][second],small[first][second]}; // 기록한 값 리턴
    }
}


int main(void)
{
    // nCm 구하기 -> 조합론
    int_64 n, m;
    cin >> n >> m;
    // 1. nCm = nCm-n임 2.하키스틱 정리로 분해해서 풀 수 있음
    memset(small,-1,sizeof(small));
    memset(big, 0, sizeof(big));
    // 하키스틱 정리에 의해 nCm = n-1Cm-1 + n-2Cm-1 +.... + m-1Cm-1
    pair<int_64,int_64> ans = {0,0};
    ans = hockeystick(n, m);
    if(ans.first > 0)
        cout << ans.first << ans.second << "\n";
    else
        cout << ans.second << '\n';
    return 0;
}