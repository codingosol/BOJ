#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        int n, m; // n은 수첩 1, m은 수첩 2
        cin >> n;
        vector<int> v;
        int temp;
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        cin >> m;
        for(int k = 0; k < m; k++)
        {
            cin >> temp;
            if(binary_search(v.begin(),v.end(),temp)) // 찾았다면
            {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }
    return 0;
}