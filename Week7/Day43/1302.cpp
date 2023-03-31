#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    map<string,int> m;
    for(int i =0 ; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if(m.find(tmp) != m.end()) // 이미 존재한다면
        {
            m[tmp] += 1;
        }
        else {
            m[tmp] = 1;
        }
    } // input
    // sort(m.begin(),m.end(), cmp); // 사전순 정렬
    int max = 0;
    string ans;
    for(auto i : m)
    {
        if(i.second > max)
        {
            max = i.second;
            ans = i.first;
        }
    }
    cout << ans << '\n';
    return 0;
}