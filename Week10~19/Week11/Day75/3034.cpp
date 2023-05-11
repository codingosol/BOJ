#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n, w, h;
    cin >> n >> w >> h;
    double val = sqrt(pow(w,2) + pow(h,2));
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp <= val)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
    return 0;
}