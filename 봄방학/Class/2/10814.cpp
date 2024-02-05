#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<int,string>,int> a, pair<pair<int,string>,int> b)
{
    if(a.first.first < b.first.first)
    {
        return true;
    }
    else if(a.first.first == b.first.first)
    {
        return a.second < b.second;
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
    int age;
    vector<pair<pair<int,string>,int>> v;
    for(int i = 0; i < n; i++)
    {
        cin >> age >> str;
        v.push_back({{age,str},i});
    }
    sort(v.begin(),v.end(),cmp);
    // 나이가 같으면 가입한 순
    // 3중 pair로 구현
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first.first << ' ' << v[i].first.second << '\n';
    }
    return 0;
}