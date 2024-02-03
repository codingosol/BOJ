#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int max = -987654321; int min = 987654321;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp > max)
        {
            max = temp;
        }
        if(temp < min)
        {
            min = temp;
        }
    }
    cout << min << ' ' << max << '\n';
    return 0;
}