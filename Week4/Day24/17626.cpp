#include <iostream>
using namespace std;

#define MIN 50000

int main(void)
{
    int n;
    cin >> n;
    // n을 최소 개수의 제곱수 합으로 표현
    int arr[50001];
    // n을 최소 개수의 제곱수로 표현하려면 일단 n보다 작은 최대 제곱수를 잡고
    // 남은 수를 계속 최대 제곱수로 나타낼 수 있는지 판단 -> 불가능할 경우 
    // 처음으로 돌아와 제곱수를 하나 낮춤 -> 루트 n 아래일 경우 포기(하지만 이런 경우는 없을 것)
    // 50000을 넘지 않는 최대의 제곱수는 223이다
    arr[1] = 1;
    // i보다 작은 제곱수를 i에서 뺀 수중에 가장 작은 값에서 최솟값에 1을 더하면 됨
    for(int i = 2; i <= n; i++)
    {
        int min = MIN;
        for(int j = 1; j * j <= i; j++)
        {
            if(arr[i - j*j] < min)
                min = arr[i - j*j];
        }
        arr[i] = min + 1;
    }
    cout << arr[n] << "\n";
    return 0;

}