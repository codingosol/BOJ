#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int cnt1 = 0, cnt2 = 0; // 스킬이 정상적으로 사용된 횟수
    vector<int> v1, v2;
    int time1 = 0, time2 = 0; // 마지막으로 적용된 스킬을 사용한 시점
    // 쿨이 안돌았거나, 이미 적용중이면 면역임
    // 쿨이 면역시간보다 기므로 면역시간은 계산할 필요가 없을텐데...
    // 순서대로가 아님 -> 정렬 필요
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(),v1.end());
    for(int i = 0; i < n; i++)
    {
        if(i == 0 ||time1 + 100 <= v1[i]) // 100초가 지나기 전까지는 스킬 재사용 불가
        {
            time1 = v1[i];
            cnt1++;
        }
    }
    for(int j = 0; j < m; j++)
    {
        cin >> temp;
        v2.push_back(temp);
    }
    sort(v2.begin(),v2.end());
    for(int j = 0; j < m; j++)
    {
        if(j == 0 || time2 + 360 <= v2[j]) // 360초가 지나기 전까지는 스킬 재사용 불가능
        {
            time2 = v2[j];
            cnt2++;
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
    return 0;
}