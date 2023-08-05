#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        if (v.empty() || v.back() < temp)
		{
			v.push_back(temp);
		}
        else
		{
			auto iterator = lower_bound(v.begin(), v.end(), temp);
			*iterator = temp;
		}
	}
	cout << v.size();
}