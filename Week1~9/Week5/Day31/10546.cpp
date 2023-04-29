#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    map<string,int> m;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(m.find(str) != m.end()) // 이미 있다면
        {
            m[str]++;
        }
        else {
            m[str] = 1;
        }
    }
    for(int j = 0; j < n -1; j++)
    {
        cin >> str;
        m[str]--;
    }
    for(auto i : m)
    {
        if(i.second > 0)
        {
            cout << i.first << "\n";
        }
    }
    return 0;
}