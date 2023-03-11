#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string palindrom(string str)
{
    string temps;
    temps.resize(str.length());
    for(int i = 0; i < str.length(); i++)
    {
        temps[i] = str[str.length() - i - 1];
    }
    return temps;
}

int main(void)
{
    int n;
    cin >> n;
    string str;
    vector<string> v;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        v.push_back(str);
    }
    for(int i = 0; i < n; i++)
    {
        str = palindrom(v[i]);
        for(int j = 0; j < n; j++)
        {
            if(str == v[j])
            {
                cout << v[j].length() << " " << str[str.length() / 2] << "\n";
                return 0;
            }
        }
    }
    return 0;
}