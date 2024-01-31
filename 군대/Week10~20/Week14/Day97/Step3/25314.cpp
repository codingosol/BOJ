#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while(n > 0)
    {
        n -= 4;
        cout << "long ";
    }
    cout << "int\n";
    return 0;
}