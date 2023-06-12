#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int ac[100001];

int main(void)
{
    // 완전탐색으로는 시간 초과가 남
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ac[i] = ac[i-1] + arr[i];
    }
    /*int max_val = -987654321;
    for(int i = 1; i <= n - m; i++)
    {
        int temp = 0;
        for(int j = 1; j <= m; j++)
        {
            temp += arr[i+j-1];
        }
        if(max_val < temp)
            max_val = temp;
        //cout << "current val is : " << max_val << '\n';
    }*/
    // 누적합 배열을 구해서 누적합 배열끼리 빼주면 됨
    int max_val = -987654321;
    for(int i = m; i <= n; i++)
    {
        int temp = ac[i] - ac[i-m];
        if(max_val < temp)
            max_val = temp;
    }
    cout << max_val << '\n';
    return 0;
}