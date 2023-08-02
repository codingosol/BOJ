#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >> n;
        vector<string> v;
        string str;
        for(int i = 0; i < n; i++)
        {
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(),v.end()); // 길이 순으로 정렬해야 할 것 같음
        // 왜냐하면 더 긴 문자열이 접두사가 될 수는 없기 때문
        bool flag = true;
        // 정렬 한 후 현재 문자열이 다음 문자열의 접두사가 될 수 있는지 판단
        for(int i = 0; i < v.size() - 1; i++)
        {
            string cur = v[i];
            string next = v[i+1];
            flag = true;
            // 접두사가 될 수 있는지 판단
            if(cur.size() > next.size())
                continue;
            if(cur == next.substr(0,cur.length()))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}