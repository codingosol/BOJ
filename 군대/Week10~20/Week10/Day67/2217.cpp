#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> rope;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),greater<int>()); // 내림차순으로 정렬
    // 최대로 들 수 있는 중량은 가장 들수 있는 중량이 낮은 로프 * 로프 개수임
    int max_w = 0;
    for(int i = 0; i < n; i++)
    {
        int min_rope = v[i]; // 내림차순 정렬해놓았기 떄문
        if(max_w < min_rope * (i + 1))
            max_w = min_rope*(i+1);
    }
    cout << max_w << '\n';
    return 0;
}