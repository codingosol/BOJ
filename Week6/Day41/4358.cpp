#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    string str;
    double cnt = 0;
    map<string,double> m;
    while(getline(cin,str))
    {
        cnt++;
        if(m.find(str) != m.end()) // 이미 있다면
        {
            m[str] += 1;
        }
        else {
            m[str] = 1;
        }
    } // input
    cout << fixed;
    cout.precision(4);
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " ";
        double val = (iter->second / cnt) * 100;
        cout << val << '\n';
    }
    return 0;
}