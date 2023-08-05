#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int_64;

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
    // 수식 | a[0] - a[1] | + | a[1] - a[2] | + ... 
    // 이 수가 최대가 되려면 양수 항의 수는 최대가 되야 하고 음수항의 수는 최소가 되어야 함
    sort(v.begin(),v.end());
    int front = 0;
    int end = v.size() - 1;
    int_64 ans = 0;
    // 홀수일 경우를 생각해야 함
    // 
    while(front <= end)
    {
        if(front == end) // 홀수라서 겹치는 경우
        {
            ans += abs(v[front]) * 2;
        }
        ans += v[end] - v[front];
        end--;
        front++;
    }
    cout << ans << '\n';
    return 0;
}