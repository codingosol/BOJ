#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[4] = {0,0,0,0};
    string str;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> str >> temp;
        if(str == "STRAWBERRY")
        {
            arr[0] += temp;
        }
        else if(str == "PLUM")
        {
            arr[1] += temp;
        }
        else if(str == "BANANA")
        {
            arr[2] += temp;
        }
        else if(str == "LIME")
        {
            arr[3] += temp;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(arr[i] == 5)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}