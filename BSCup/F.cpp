#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    char ch;
    int mass = 0;
    int applecnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> ch;
        int w, d, h;
        if(ch == 'A') // 사과상자
        {
            cin >> w >> d >> h;
            // 사과가 12cm의 정육면체이므로 최소값을 얻으면 됨
            int max_w = 987654321;
            int max_d = 987654321;
            int max_h = 987654321;
            if(w / 12 < max_w)
            {
                max_w = w / 12;
            }
            if(d / 12 < max_d)
            {
                max_d = d / 12;
            }
            if(h / 12 < max_h)
            {
                max_h = h / 12;
            }
            // 사과 하나에 500g 포장 1000g
            mass += 500 * (max_w * max_h * max_d) + 1000;
            applecnt += max_w * max_h * max_d;
        }
        else { // 배상자
            cin >> w >> d >> h;
            // 배상자는 상관없이 6000의 질량을 지님
            mass += 6000;
        }
    }
    cout << mass << '\n';
    cout << applecnt * 4000 << '\n';
    return 0;
}