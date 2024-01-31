#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int_64;

int main(void)
{
    int n;
    cin >> n;
    int_64 temp;
    vector<int_64> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    vector<int_64> v2(v);
    sort(v.begin(),v.end()); // 정렬
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i < n; i++)
    {
        cout << lower_bound(v.begin(),v.end(),v2[i]) - v.begin() << " ";
    }
    cout << "\n";
    return 0;
}