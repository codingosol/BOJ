#include <iostream>

using namespace std;

int main(void)
{
    int e, s, m;
    cin >> e >> s >> m;
    int ce, cs, cm;
    ce = 1, cs = 1, cm = 1;
    int cnt = 1;
    while(true)
    {
        if(ce == e && cs == s && cm == m)
        {
            break;
        }
        else {
            ce = (ce) % 15 + 1;
            cs = (cs) % 28 + 1;
            cm = (cm) % 19 + 1;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}