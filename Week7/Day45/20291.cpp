#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int num;
    cin >> num;
    map<string,int> m; // string이 key, 개수가 int
    string str;
    for(int i = 0; i < num; i++)
    {
        cin >> str;
        bool flag = false;
        string exe;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '.')
            {
                flag = true;
                continue;
            }
            if(flag)
            {
                exe += str[j];
            }
        }
        if(m.find(exe) != m.end())
        {
            m[exe]++;
        }
        else {
            m[exe] = 1;
        }
    }
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << ' ' << iter->second << '\n';
    }
    return 0;
}