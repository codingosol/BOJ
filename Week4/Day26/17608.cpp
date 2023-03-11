#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    int maxh = 0;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(v[i] > maxh)
        {
            cnt++;
            maxh = v[i];
        }
    }
    cout << cnt << "\n";
    return 0;
}