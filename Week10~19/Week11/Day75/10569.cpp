#include <iostream>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    int v, e, f; // 각각 꼭짓점 모서리 면 
    while(testcase--)
    {
        cin >> v >> e;
        f = 2 + e - v;
        cout << f << '\n';
    }
    return 0;
}