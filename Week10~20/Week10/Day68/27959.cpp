#include <iostream>

using namespace std;

int main(void)
{
    int num, money;
    cin >> num >> money;
    if(num * 100 >= money)
    {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}