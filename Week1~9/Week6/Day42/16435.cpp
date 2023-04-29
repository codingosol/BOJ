#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int num, h;
    cin >> num >> h;
    int temp;
    vector<int> v;
    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] <= h)
        {
            h++;
        }
    }
    cout << h << '\n';
}