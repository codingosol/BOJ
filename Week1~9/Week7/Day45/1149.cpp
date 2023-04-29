#include <iostream>

using namespace std;

int arr[1000][3]; // 각각 R,G,B

int main(void)
{
    int num;
    cin >> num;
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    for(int i = 1; i <= num; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        arr[i][0] = min(arr[i - 1][1],arr[i - 1][2]) + r;
        arr[i][1] = min(arr[i - 1][0],arr[i - 1][2]) + g;
        arr[i][2] = min(arr[i - 1][1],arr[i - 1][0]) + b;
    }
    cout << min(arr[num][0],min(arr[num][1],arr[num][2])) << '\n'; 
    // 이웃한 집끼리는 같은 색이 될 수 없음
    // 브루트포스로 풀 경우 3 ^ 1000 가짓수이므로 시간초과
    return 0;
}