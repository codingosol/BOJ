#include <iostream>

using namespace std;

bool arr[9] = {false,};

int main(void)
{
    int temp;
    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        arr[temp] = !arr[temp];
    }
    for(int i = 0; i <= 9; i++)
    {
        if(arr[i] == true)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}