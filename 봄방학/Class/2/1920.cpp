#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    int temp;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        int front = 0;
        int back = v.size()-1;
        bool flag = false;
        while(front <= back)
        {
            int mid = (front + back) / 2;
            if(temp < v[mid]) // 작으면 end 당겨옴
            {
                back = mid - 1;
            }
            else if(temp > v[mid]) // 크면 front 밈
            {
                front = mid + 1;
            }
            else {
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}