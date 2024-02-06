#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    if(n == 0)
    {
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    // 30% 절사평균
    // 상위 15% 하위 15%를 빼야 함
    long double avg;
    int total = 0;
    int k = round(n * 0.15); // 위, 아래에서 빼야 하는 인원수
    for(int i = 0 + k; i < n - k; i++)
    {
        total += v[i];
    }
    avg = (double)total / (n-2*k);
    cout << round(avg) << '\n';
    return 0;
}