#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int w, h;
    pair<int,int> arr[50];
    for(int i = 0; i < n; i++)
    {
        cin >> w >> h;
        arr[i] = {w,h};
    }
    // 이제 덩치 순위를 매겨야함
    // 덩치가 밀릴 때 순위를 +1 하면 됨
    int rank[50];
    fill_n(rank,50,1); // 모두 처음에는 1위
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i].first > arr[j].first && arr[i].second > arr[j].second) // 덩치 승리
            {
                rank[j]++;
            }
            else if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) // 덩치 패배
            {
                rank[i]++;
            }
            else {
                // 비기면 스킵
                continue;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << rank[i] << ' ';
    }
    cout << '\n';
    return 0;
}