#include <iostream>

using namespace std;

int main(void)
{
    int num[10] = {0,};
    int a, b, c;
    cin >> a >> b >> c;
    int res = 0;
    res = a * b * c;
    while(res > 0)
    {
        int temp = res % 10;
        res /= 10;
        num[temp]++;
    }
    for(int i = 0; i <= 9; i++)
    {
        cout << num[i] << '\n';
    }
    return 0;
}