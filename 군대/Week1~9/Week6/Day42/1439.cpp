#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int zerocnt = 0;
    int onecnt = 0;
    // 0으로 뒤집는 횟수와 1로 뒤집는 횟수의 차이
    for(int i = 0; i < str.length();)
    {
        if(str[i] == '0')
        {
            zerocnt++;
            while(str[i] == '0')
            {
                i++;
            }
        }
        else if(str[i] == '1')
        {
            onecnt++;
            while(str[i] == '1')
            {
                i++;
            }
        }
    }
    cout << min(zerocnt,onecnt) << '\n';
    return 0;
}