#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int val = 1;
    // 오름차순으로 출력
    // n*2-1의 최대 넓이를 가짐
    for(int i = 1; i < n; i++) // 오름차순 출력
    {
        // 1. n - i 만큼의 빈칸 출력
        for(int j = 0; j < n-i; j++)
        {
            cout << ' ';
        }
        // 2. i*2-1만큼 * 출력
        for(int j = 0; j < i*2-1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    for(int i = 0; i < n*2-1; i++)
    {
        cout << '*';
    }
    cout << '\n';
    for(int i = n-1; i > 0; i--) // 내림차순 출력
    {
        // 1. n - i 만큼의 빈칸 출력
        for(int j = 0; j < n-i; j++)
        {
            cout << ' ';
        }
        // 2. i*2-1만큼 * 출력
        for(int j = 0; j < i*2-1; j++)
        {
            cout << '*';
        }
        // 3. 1과 동일
        cout << '\n';
    }
}
