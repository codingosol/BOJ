#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int temp;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int m;
    cin >> m;
    for(int j = 0; j < m; j++)
    {
        cin >> temp;
        int start = 0, end = v.size() - 1;
        int mid;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(v[mid] > temp)
            {
                end = mid - 1;
            }
            else if(v[mid] < temp)
            {
                start = mid + 1;
            }
            else { // 찾았을 경우
                cout << "1 ";
                break;
            }
        }
        if(start > end)
        {
            cout << "0 ";
        }
    }
    cout << "\n";
    return 0;
}