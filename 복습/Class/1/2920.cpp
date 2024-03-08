#include <iostream>

using namespace std;

int main(void)
{
    int arr[8];
    bool flag_des = true, flag_asc = true;
    for(int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    // 오름차순 검사
    for(int i = 1; i < 8; i++)
    {
        if(arr[i] != arr[i-1] + 1)
        {
            flag_asc = false;
            break;
        }
    }
    for(int i = 1; i < 8; i++)
    {
        if(arr[i] != arr[i-1] -1)
        {
            flag_des = false;
            break;
        }
    }
    if(flag_asc)
        cout << "ascending\n";
    else if(flag_des)
        cout << "descending\n";
    else
        cout << "mixed\n";
    return 0;
}