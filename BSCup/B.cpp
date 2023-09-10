#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        if(m <= 4500)
        {
            if(m <= 1000)
            {
                if(m <= 25)
                {
                    cout << "Case #" << i << ": World Finals\n";
                }
                else {
                    cout << "Case #" << i << ": Round 3\n";
                }
            }
            else {
                cout << "Case #" << i << ": Round 2\n";
            }
        }
        else {
            cout << "Case #" << i << ": Round 1\n";
        }
    }
    return 0;
}