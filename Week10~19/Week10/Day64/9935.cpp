#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    // 일반적인 substr을 사용했을 때 메모리 초과가 남
    // stack으로 함 해보자
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    stack<char> stk;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++)
    {
        stk.push(str[i]);
        if(str[i] == bomb[cnt]) // 폭탄으로 의심할 수 있다면
        {
            bool flag = true;
            while(cnt < bomb.length())
            {
                i++;
                cnt++;
                if(str[i] != bomb[cnt])
                {
                    flag  = false;
                    break;
                }
            }
            if(flag) // 끝까지 탐색한 결과 폭탄이라면
            {
                for(int j = 0; j < bomb.length(); j++)
                {
                    stk.pop();
                }
            }
        }
    }
}