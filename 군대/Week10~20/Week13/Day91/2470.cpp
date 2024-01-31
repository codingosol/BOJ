#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int_64;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int_64> v;
    int_64 temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    int idx_s = 0, idx_e = n-1; // 0과 가장 가까운 값일 때 그 두 수를 가리킬 변수
    int ans_f = 0, ans_e = n-1; // 답 위치를 저장할 변수
    int_64 val = 121110987654321; // 현재 가장 0과 가까운 합성값
    while(idx_s < idx_e) // 중간값이 정답이 아닐 수도 있음
    {
        //cout << "current index is : " << idx_s << ' ' << idx_e << '\n';
        //cout  << mid << '\n';
        int_64 tmpval = v[idx_s] + v[idx_e];
        //cout << tmpval << '\n';
        if(abs(tmpval) < abs(val))
        {
            val = tmpval;
            ans_f = idx_s;
            ans_e = idx_e;
        }
        if(tmpval == 0)
        {
            break;
        }
        if(tmpval > 0)
        {
            // 양수값이라면 값을 감소시켜야함
            idx_e--;
        }
        else if(tmpval < 0)
        {
            // 음수라면 값을 증가시켜야함
            idx_s++;
        }
    }
    cout << v[ans_f] << ' ' << v[ans_e] << '\n';
    return 0;
}