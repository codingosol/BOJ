#include <iostream>

using namespace std;

int main(void)
{
    int n, v, l;
    cin >> n >> v >> l;
    if(n >= 1000)
    {
        if(v >= 8000 || l >= 260)
        {
            cout << "Very Good\n";
        }
        else {
            cout << "Good\n";
        }
    }
    else {
        cout << "Bad\n";
    }
    return 0;
}