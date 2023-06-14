#include <iostream>
#include <vector>

using namespace std;
int picked[32]; // 몇 번 사람을 골랐는지 표기 0~31 최대 32명 저장
int n; // 사람 수
int min_val = 987654321;

int solve(vector<string> &v)
{
    // 세 문자열을 비교해서 값 출력
    vector<string> strs;
    for(int i = 0; i < n; i++)
    {
        if(picked[i] == 1)
        {
            strs.push_back(v[i]); // 셋 고른 문자열 추가
        }
    }
    //1. a와 b 비교
    // cout << strs[0] << ' ' << strs[1] << ' ' << strs[2] << '\n';
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        if(strs[0][i] != strs[1][i])
        {
            cnt++;
        }
    }
    // 2. b와 c 비교
    for(int i = 0; i < 4; i++)
    {
        if(strs[1][i] != strs[2][i])
        {
            cnt++;
        }
    }
    // 3. a와 c 비교
    for(int i = 0; i < 4; i++)
    {
        if(strs[2][i] != strs[0][i])
        {
            cnt++;
        }
    }
    // cnt값 리턴
    return cnt;
}

void pick(vector<string> &v,int cnt) // 백트래킹을 이용해 3개 고름
{
    if(cnt == 0)
    {
        int val = solve(v);
        if(val < min_val) // 최솟값 갱신
            min_val = val;
        return;
    }
    else {
        for(int i = 0; i < n; i++) // n개 중에 고름
        {
            if(picked[i] == 0)
            {
                picked[i] = 1;
                pick(v,cnt-1);
                picked[i] = 0; // 백트래킹
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        cin >> n;
        // ENTJ INTP ESFJ / INFP INFP ESTP ESTJ ISTJ
        // 성격 유형이 총 16개이므로 32명까지는 2명씩 존재하지만 33부터는 3명이 되므로 무조건 0이 될 수 밖에 없음
        if(n > 32)
        {
            cout << "0\n";
            continue;
        }
        vector<string> v;
        string str;
        for(int i = 0; i < n; i++)
        {
            cin >> str;
            v.push_back(str);
        }
        // n개 중에서 3개 고르기
        pick(v,3);
        cout << min_val << '\n';
        min_val = 987654321; // 최솟값 초기화
    }
}