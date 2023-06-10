#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> p1, pair<string,int> p2)
{
    if(p1.second != p2.second) // 횟수
    {
        return p1.second > p2.second;
    }
    else {
        if(p1.first.length() != p2.first.length()) // 길이
        {
            return p1.first.length() > p2.first.length();
        }
        else { // 알파벳 순
            return p1.first < p2.first;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string str;
    map<string,int> dict; // map은 기본적으로 알파벳 순으로 정렬됨
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str.size() < m)
            continue;
        else
        {
            if(dict.find(str) != dict.end())
            {
                dict[str]++;
            }
            else {
                dict[str] = 1;
            }
        }
    }
    // 등장 횟수와 길이, 문자열을 모두 저장했음 이를 정렬해야함
    vector<pair<string,int>> v = {dict.begin(), dict.end()};
    sort(v.begin(), v.end(), cmp);
    for(auto i : v)
    {
        cout << i.first << '\n';
    }
    return 0;
}