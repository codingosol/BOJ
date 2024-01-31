#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        cout << str[0] << str[str.length()-1] << '\n';
    }
    return 0;
}