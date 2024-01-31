#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int n; // IOI의 길이를 정함
    cin >> n;
    int length;
    cin >> length; // 문자열의 길이
    string str;
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < length; i++)
    {
        int k = 0; // k는 IOI의 길이 1이면 IOI 2이면 IOIOI
        if(str[i] == 'O')
        {
            continue;
        }
        else {
            while(str[i + 1] == 'O' && str[i + 2] == 'I') //IOI가 유지되는 동안
            {
                k++; // k의 길이 증가
                if(k == n) // k가 n과 일치하게 되면
                {
                    k--; // 중복 카운트 방지
                    cnt++;
                }
                i += 2; // 두 칸 당기
            }
            k = 0;
        }
    }
    cout << cnt << "\n";
    return 0;

}