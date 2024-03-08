#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[1001];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } // input;
    int dpu[1001]; // up dp
    int dpd[1001]; // down dp
    // 최대 오름차순과 최대 내림차순을 dp로 구한 다음
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dpu[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if(arr[i] > arr[j])
            {
                dpu[i] = max(dpu[i], dpu[j] + 1);
            }
        }
    } // up dp의 값 구함
    for(int i = n; i >= 1; i--)
    {
        dpd[i] = 1;
        for(int j = n; j >= i; j--)
        {
            if(arr[i] > arr[j])
            {
                dpd[i] = max(dpd[i],dpd[j] + 1);
            }
        }
    } // down dp의 값 구함
    // 이제 올라가는 수열과 내려가는 수열의 최대합을 구해야 함
    // 그리고 수열은 혼자서도 1이므로 겹치기 때문에 -1
    for(int i = 1; i <= n; i++)
    {
        if(dpd[i] + dpu[i] - 1 > ans)
        {
            ans = dpd[i] + dpu[i] - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}