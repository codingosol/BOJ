#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    map<string,int> m;
    int n, h;
    cin >> n >> h;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        m[str] = 1; // 중복으로 주어지지 않으므로 이렇게 해도 됨
    }
    int cnt = 0;
    for(int i = 0; i < h; i++)
    {
        cin >> str;
        if(m.find(str) != m.end()) // 이미 있다면
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}