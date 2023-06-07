#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    /*각 막대의 길이는 양의 정수이다
    세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
    삼각형의 둘레를 최대로 해야 한다.*/
    int a, b, c;
    cin >> a >> b >> c;
    // 짧은 두 막대의 길이가 가장 긴 막대의 길이보다 길어야 삼각형을 구성할 수 있음
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    // 크기순으로 정렬
    if(v[0] + v[1] <= v[2]) // 삼각형 구성 불가능
    {
        // 줄여서 출력
        cout << (v[0]+v[1])*2-1 << '\n';
    }
    else {
        cout << v[0] + v[1] + v[2] << '\n';
    }
    return 0;
}
