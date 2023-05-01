#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    vector<int> v;
    for(int i = 0; i < str.length(); i++)
    {
        v.push_back(str[i] - '0');
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << '\n';
    return 0;
}