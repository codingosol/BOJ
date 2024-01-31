#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int temp;
    vector<int> v;
    // n명중 m번째까지의 수
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout << v[v.size() - m] << '\n';
    return 0;
}