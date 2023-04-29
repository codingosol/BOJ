#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    char c;
    getchar(); // \n 비움
    stack<char> stk1;
    stack<char> stk2;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        c = getchar(); // 한 글자씩 받음
        if(c - '0' >= 1 && c - '0' <= 9) // 숫자일 경우
        {
            cnt++; // 위치에 상관없이 기술 나감
        }
        else // 연계기일 때
        {
            if(c == 'S')
            {
                stk1.push('S');
            }
            else if(c == 'K')
            {
                if(!stk1.empty() && stk1.top() == 'S')
                {
                    stk1.pop();
                    cnt++;
                }
                else {
                    cout << cnt << "\n";
                    return 0;
                }
            }
            else if(c == 'L')
            {
                stk2.push('L');
            }
            else if(c == 'R')
            {
                if(!stk2.empty() && stk2.top() == 'L')
                {
                    stk2.pop();
                    cnt++;
                }
                else
                {
                    cout << cnt << "\n";
                    return 0;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}