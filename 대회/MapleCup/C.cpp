#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int_64;

vector<int_64> character;
pair<int_64,int> boss[14];
int knapsack[14][901]; // 시간 내 잡을 수 있는 최대 메소

int main(void)
{
    int_64 n, m, k; // 각각 캐릭터의 수, 쓸 캐릭터 수, 보스몹 수
    cin >> n >> m >> k;
    int_64 temp;
    // 한 캐릭당 최대 허용된 시간은 15분임
    for(int i = 0; i < n; i++)
    {
        cin >> temp; // 캐릭이 초당 가하는 딜량
        character.push_back(temp);
    }
    sort(character.begin(),character.end(),greater<int_64>()); // 딜 높은순으로 정렬
    // 냅색 문제?
    int_64 a, b;
    for(int j = 1; j <= k; j++)
    {
        cin >> a >> b; // 보스의 피통과 메소
        boss[j] = {a,b};
    }
    // 캐릭은 무조건 딜 높은 캐릭을 고르는게 이득임
    // 15분동안 메소를 최대한 많이 뽑아먹을 수 있게 냅색 만들면 됨
    // 15분은 900초
    int_64 meso = 0; // 얻을 수 있는 총 메소
    for(int s = 0; s < m; s++) // m개의 캐릭터에 대해 연산 실시
    {
        // 맨 앞의 캐릭터가 딜이 제일 높으므로 char[0]부터 m회 실시
        // 보스 딜은 1초 단위로 계산되므로 올림 처리해줘야함
        fill_n(knapsack[0],14*901,0); // 초기화
        int_64 dps = character[s];
        //cout << dps << '\n';
        for (int i = 1; i <= k; i++) // 보스몹
        { 
            for (int j = 1; j <= 900; j++) { // 시간
                if (int(ceil((double(boss[i].first) / dps)) > j)) // j초 내에 보스를 잡을 수 없다면
                    knapsack[i][j] = knapsack[i - 1][j]; // 전의 노드와 동일
                else // j초 내에 이 보스를 잡을 수 있다면 {이 보스를 잡기 전에 벌 수 있었던 최대 메소 vs 현재 보스를 잡는데 걸리는 시간 전의 최대 메소 + 잡아서 번 메소} 비교
                {
                    knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i - 1][j - int(ceil(double(boss[i].first) / dps))] + boss[i].second);
                }
            }
        }
        // cout << knapsack[k][900] << '\n';
        meso += knapsack[k][900];
    }
    cout << meso << '\n';
    return 0;
}