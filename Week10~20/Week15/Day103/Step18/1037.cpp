#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    // 약수 처음과 끝 곱하기
    cout << v[0] * v[v.size()-1] << '\n';
    return 0;
}