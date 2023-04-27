#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first < p2.first;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int num;
        cin >> num;
        vector<pair<int,int>> v;
        for(int i = 0; i < num; i++)
        {
            int t1, t2;
            cin >> t1 >> t2; // t1은 필기, t2는 실기
            v.push_back({t1,t2});
        } // input
        // 정렬해야 함 그렇지 않으면 n^n의 탐색이 필요함
        // 재검사하면 안됨 -> 아래로 내려가면서 위를 다시 찾아서 갯수를 빼거나 하면 안 된다는 뜻
        // 한쪽 기준으로 정렬 -> first로 정렬
        sort(v.begin(),v.end(),cmp);
        int cnt = 1;
        int max_val = v[0].second;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i].second < max_val)
            {
                cnt++;
                max_val = v[i].second;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}