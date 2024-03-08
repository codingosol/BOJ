#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    if(a.length() < b.length())
        return true;
    else if(a.length() == b.length())
    {
        return a < b;
    }
    else {
        return false;
    }
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
        if(find(v.begin(),v.end(),str) != v.end())
        {
            continue;
        }
        else {
            v.push_back(str);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
    return 0;
}