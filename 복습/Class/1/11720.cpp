#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int total = 0;
    int temp;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        temp = int(cin.get());
        // cout << temp << '\n';
        total += temp - 48;
    }
    cout << total << '\n';
    return 0;
}