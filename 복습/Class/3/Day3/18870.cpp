#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v, v2;
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        v2.push_back(temp);
    }
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    for(int i = 0; i < n; i++)
    {
        cout << lower_bound(v2.begin(),v2.end(),v[i]) - v2.begin() << '\n';
    }
    return 0;
}