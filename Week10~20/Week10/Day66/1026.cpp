#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> A;
    vector<int> B;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        B.push_back(temp);
    }
    // S의 값을 최소로 하기 위해서는 A의 가장 큰 값과 B의 가장 작은 값을 매칭시키는 방법으로 해야 함
    // B를 재배열하면 안 된다는 조건은 의미가 없음
    sort(A.begin(), A.end()); // 오름차순 정렬
    sort(B.begin(), B.end(), greater<int>()); // 내림차순 정렬
    int S= 0;
    for(int i = 0; i < A.size(); i++)
    {
        S += A[i] * B[i];
    }
    cout << S << '\n';
    return 0;
}