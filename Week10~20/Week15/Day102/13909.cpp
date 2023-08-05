#include <iostream>

using namespace std;
typedef long long int_64;

int main(void)
{
    // n은 최대 2100000000
    int_64 n;
    cin >> n;
    // 배열로 생각해서 푸는 것은 불가능 2100000000 * 4 byte는 메모리 초과가 남
    // 자신의 약수의 개수가 홀수이면 열림, 짝수면 닫힘 상태
    // 약수 개수를 어케 알지
    // 1~n까지의 수의 약수 개수를 계산해서 홀수면 cnt++ 약수 개수를 구하는 알고리즘이 필요
    // 약수 개수가 홀수인 수는 1과 '제곱수' 밖에 없음
    int cnt = 0;
    for(int i = 1; i*i <= n; i++)
    {
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}