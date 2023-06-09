#include <iostream>

using namespace std;

int main(void)
{
    // 연립방정식 ax+by = c;
    //           dx+ey = f;
    // 의 x,y의 해를 구하여라
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int i = -999; i <= 999; i++)
    {
        for(int j = -999; j <= 999; j++)
        {
            if(a*i+b*j == c && d*i+e*j == f)
            {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
}