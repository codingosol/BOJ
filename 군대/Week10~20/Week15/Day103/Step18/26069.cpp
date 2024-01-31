#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string a, b;
    map<string,int> m;
    m["ChongChong"] = 2; // 총총이는 댄스를 추고있다
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        // 없다면 추가
        if(m.find(a) == m.end())
        {
            m[a] = 1;
        }
        if(m.find(b) == m.end())
        {
            m[b] = 1;
        }
        if(m[a] == 2 || m[b] == 2) // 둘 중 한명이 댄스를 추고 있다면 댄스가 전염됨
        {
            m[a] = 2;
            m[b] = 2;
        }
    }
    // 이제 map을 순환하며 2인 값들을 세서 추가
    for(auto i : m)
    {
        if(i.second == 2)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}