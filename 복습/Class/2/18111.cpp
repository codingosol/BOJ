#include <iostream>

using namespace std;

int arr[500][500];

int main(void)
{
    int n, m, b;
    cin >> n >> m >> b;
    // 블록을 채우는 데 1초
    // 블록을 제거하는데 2초 걸림
    int max_h = 0;
    int min_h = 987654321;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > max_h)
                max_h = arr[i][j];
            if(arr[i][j] < min_h)
                min_h = arr[i][j];
        }
    } // input;
    // cout << min_h << ' ' << max_h << '\n';
    // 층수를 n으로 맞추는 데 걸리는 모든 시간을 브루트포스로 비교
    // 가진 블록이 있어야 쓸 수 있음
    int min_time = 987654321;
    int h = 0;
    for(int t = min_h; t <= max_h; t++) // 모든 높이 판단
    {
        int time = 0;
        int block = b;
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] > t) // 높이가 높을 경우 깎음
                {
                    time += (arr[i][j] - t) * 2;
                    block += (arr[i][j] - t);
                }
                else if(arr[i][j] < t) // 높이가 낮을 경우 올림
                {
                    time += t - arr[i][j];
                    block -= (t - arr[i][j]);
                }
                // 같을 경우는 아무 일도 일어나지 않음
            }
        }
        if(block < 0)
            flag = false;
        //cout << time << '\n';
        if(flag)
        {
            if(time < min_time)
            {
                min_time = time;
                h = t;
            }
            else if(time == min_time)
            {
                if(t > h) // 땅의 높이가 높은 것으로
                    h = t;
            }
        }
    }
    cout << min_time << ' ' << h << '\n';
    return 0;
}