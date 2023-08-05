#include <iostream>
#include <cmath>

using namespace std;

void delstr(string &str, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        str[i] = ' ';
    }
}

void solve(string &str, int start, int end, int len) // 3^n-1만큼의 길이를 삭제한 뒤 n-1로 넘김
{
    // n=2여서 길이가 9라고 가정할 시 지워야 할 인덱스는 3 4 5 임
    // 현재 길이에서 삼등분을 쳐서 각 함수를 써야 함
    if(len == 1) // 길이가 1이면 더 못나눔
        return;
    else
    {
        solve(str, start, start + len/3-1, len/3);
        delstr(str,start+len/3,start+len*2/3-1);
        solve(str, start+len*2/3, end, len/3);
    }
}

int main(void)
{
    int n;
    while(cin >> n)
    {
        string str;
        for(int i = 0; i < pow(3,n); i++)
        {
            str += '-';
        }
        solve(str,0,pow(3,n)-1, pow(3,n));
        cout << str << '\n';
    }
    return 0;
}