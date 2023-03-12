#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    map<string,int> m;
    string str;
    string stat;
    vector<string> v;
    for(int i = 0; i < n; i++)
    {
        cin >> str >> stat;
        if(stat == "leave")
        {
            m[str] = 0;
        }
        else {
            m[str] = 1;
        }
    }
    for(auto i : m)
    {
        if(i.second == 1)
        {
            v.push_back(i.first);
        }
    }
    // 작업 후 남은 직원 알파벳 역순으로 정렬
    sort(v.rbegin(),v.rend());
    for(auto i : v)
    {
        cout << i << "\n";
    }
    return 0;

}