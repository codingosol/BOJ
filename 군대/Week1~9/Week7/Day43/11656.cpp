#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    vector<string> v;
    for(int i = 0; i < str.length(); i++)
    {
        string temp = str.substr(i,str.length());
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
    return 0;
}