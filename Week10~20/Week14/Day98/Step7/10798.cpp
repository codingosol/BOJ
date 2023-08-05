#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    char arr[16][16];
    string str;
    fill_n(arr[0],16*16,'%');
    for(int i = 1; i <= 5; i++)
    {
        cin >> str;
        for(int j = 1; j <= str.length(); j++)
        {
            arr[j][i] = str[j-1];
        }
    }
    for(int i = 1; i <= 15; i++)
    {
        for(int j = 1; j <= 15; j++)
        {
            if(arr[i][j] != '%')
            {
                cout << arr[i][j];
            }
        }
    }
    cout << '\n';
    return 0;
    
}