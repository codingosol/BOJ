#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int total = 0;
    while(m--)
    {
        int num, p;
        cin >> p >> num;
        total = total + p*num;
        // cout << total << '\n';
    }
    if(total == n)
    {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}