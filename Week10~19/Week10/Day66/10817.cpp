#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v;
    int temp;
    for(int i = 0; i < 3; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout << v[1] << '\n';
    return 0;
}