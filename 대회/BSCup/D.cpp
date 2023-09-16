#include <iostream>

using namespace std;

int main(void)
{
    int s, n, m;
    cin >> s >> n >> m;
    // s는 배열의 초기 크기 n은 삽입 연산의 수 m은 삭제 연산의 수
    int cnt = 0; // 현재 저장된 원소의 수
    for(int i = 0; i < n+m; i++)
    {
        int oper;
        cin >> oper;
        if(oper == 1) // 삽입하는 연산일 시
        {
            cnt++;
            if(cnt > s) // 배열의 크기 늘려야 함
            {
                s *= 2;
            }
        }
        else {
            cnt--;
        }
    }
    cout << s << '\n';
    return 0;
}