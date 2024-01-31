#include <iostream>

using namespace std;

int main(void)
{
    int f, s, t;
    cin >> f >> s >> t;
    if(f == 60 && s ==  60 && t == 60)
    {
        cout << "Equilateral\n";
    }
    else if(f+s+t == 180 && (f == s) || (s == t) || (f == t))
    {
        cout << "Isosceles\n";
    }
    else if(f+s+t == 180)
    {
        cout << "Scalene\n";
    }
    else {
        cout << "Error\n";
    }
    return 0;
}