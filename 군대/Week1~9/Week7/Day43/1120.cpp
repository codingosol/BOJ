#include <iostream>
#include <cstring> 

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;
    int min_dif = 987654321; // 최소 차이를 저장할 값
    if(a.length() != b.length())
    {
        for(int i = 0; i <= b.length() - a.length(); i++) // 길이가 완전히 같은 경우 그냥 넘어감
        {
            int dif = 0;
            for(int j = 0; j < a.length(); j++)
            {
                if(a[j] != b[i + j]) // 맞지 않는 알파벳 수 구하기
                {
                    dif++;
                }
            }
            if(dif < min_dif)
            {
                min_dif = dif;
            }
        }
        cout << min_dif << '\n';
    }
    else {
        int dif = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
            {
                dif++;
            }
        }
        cout << dif << '\n';
    }
    return 0;
}