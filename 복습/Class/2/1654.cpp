#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

int main(void)
{
    int k, n;
    cin >> k >> n; // k는 가지고 있는 랜선의 수 n은 필요한 랜선의 개수
    vector<int_64> v;
    int_64 temp;
    int_64 max_val = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> temp;
        v.push_back(temp);
        if(max_val < temp)
            max_val = temp;
    }
    // n개를 만들 수 있는 랜선의 최대 길이를 구해야 함
    // 탐색 거리 줄이게 최댓값으로 시작
    int ans = 0;
    int_64 start = 1; 
    int_64 end = max_val;
    while(start <= end)
    {
        int_64 mid = (start + end) / 2; // 중간값 설정
        //cout << mid << '\n';
        int cnt = 0;
        for(int i = 0; i < v.size(); i++)
        {
            cnt += v[i] / mid;
        }
        //cout << cnt << '\n';
        // 조각 수가 나오는 경우에도 랜선의 최대 길이를 구해야 하므로
        if(cnt >= n) // 더 많거나 같은 조각이 나올 경우
        {
            start = mid + 1;
            if(mid > ans)
                ans = mid;
        }
        else if(cnt < n) // 더 적은 조각이 나올 경우
        {
            end = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}