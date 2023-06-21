#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

int_64 p[100001]; // 각 도시의 기름값
int_64 minp = 1110987654321; // 최소 기름값

int main(void)
{
    // 비용이 가장 적은 주유소에서 비용이 갱신되기 전까지 계속 충전하는게 이득임
    int n; // 도시의 수
    cin >> n;
    vector<int_64> v;
    int_64 temp;
    for(int i = 0; i < n-1; i++)
    {
        cin >> temp;
        v.push_back(temp);
    } // 도로 저장
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i]; // 각 도시의 기름값 저장
    }
    int_64 ans = 0;
    for(int i = 1; i < n; i++) // 마지막 도시의 기름값은 계산할 필요 없음 i는 현재 정차한 도시
    {
        if(p[i] < minp)
        {
            //cout << "min price : " << p[i] << '\n';
            minp = p[i]; // 최소 기름값 갱신
            // 이제 다음 최소 기름값을 찾음
            int_64 dist = 0; // 다음 도시까지의 거리 -> 현재 잘못 계산되고 있음
            int nextp = n;
            for(int j = i+1; j < n; j++) // 값이 싸지는 다음 도시를 찾음
            {
                if(p[j] < minp)
                {
                    nextp = j;
                    break;
                }
            }
            // 이제 찾은 곳까지의 거리를 구함
            for(int j = i-1; j < nextp-1; j++) // v[i]는 i+1과 i+2번 도시 사이의 거리
            {
                // 따라서 i번 도시부터 j번 도시까지의 거리는 
                // v[i-1] + ...... + v[nextp-1]이 되어야 함
                   dist += v[j];
            }
            //cout << "next distance : " << dist << '\n';
            ans += (dist * minp); // 결괏값에 추가 후 바꿈
        }
    }
    cout << ans << '\n';
    return 0;
}