#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    vector<int> v;
    int temp;
    int total = 0;
    for(int i = 0; i < 9; i++)
    {
        cin >> temp;
        v.push_back(temp);
        total += temp;
    } // input
    // 그 다음 키 순으로 정렬해서 합이 100이 되는 경우를 브루트포스로 찾고 그걸 출력함
    sort(v.begin(), v.end());
    // 9명이므로 2명을 안 고르는 방법으로 하면 됨
    int f, s;
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(total - v[i] - v[j] == 100)
            {
                f = i;
                s = j;
                break;
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(i == f || i == s)
            continue;
        else
            cout << v[i] << '\n';
    }
    return 0;
}