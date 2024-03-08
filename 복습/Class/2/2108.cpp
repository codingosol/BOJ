#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        total += temp;
    }
    sort(v.begin(),v.end()); // 정렬
    // 1. 산술평균
    double avg;
    avg = double(total) / n;
    if(avg < 0 && avg >= -0.5)
        avg = 0;
    cout << round(avg) << '\n';
    // 2. 중앙값
    // 항상 홀수이므로 n/2가 중앙값
    cout << v[n/2] << '\n';
    // 3. 최빈값 -> 여러개일 경우 두 번째로 작은 최빈값 출력
    int max_streak = -1;
    vector<int> rep;
    for(int i = 0; i < v.size(); i++)
    {
        int streak = 0;
        while(i < v.size() - 1)
        {
            if(v[i] == v[i+1])
            {
                streak++;
                i++;
            }
            else
                break;
        }
        //cout << streak << '\n';
        if(streak > max_streak)
        {
            max_streak = streak;
            // 최빈값 벡터 초기화 후 추가
            while(!rep.empty())
            {
                rep.pop_back();
            }
            rep.push_back(v[i]);
        }
        else if(streak == max_streak)
        {
            rep.push_back(v[i]);
        }
    }
    if(rep.size() != 1) // 앞에서부터 작은 최빈값이므로
    {
        cout << rep[1] << '\n';
    }
    else
        cout << rep[0] << '\n';
    // 4. 범위
    cout << abs(v[0] - v[v.size()-1]) << '\n';
    return 0;
}