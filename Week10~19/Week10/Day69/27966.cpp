#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    // 거리가 최소가 되는 경우는 한 정점이 다른 모든 정점을 자식으로 가질 경우임
    int node;
    cin >> node;
    // 새로 만든 정점이 가지는 거리도 총 거리에 더해 추가해줘야 함
    int_64 dist = 0;
    // 1번 정점을 만들 때는 거리가 소모되지 않으나 2번 정점을 만들 때는 1개, 3번 정점의 경우는 3, 4번 정점의 경우는 5... 같이 2n-3로 소모됨
    for(int i = 2; i <= node; i++)
    {
        dist += (2*i)-3;
    } 
    cout << dist << '\n';
    for(int i = 2; i <= node; i++)
    {
        cout << 1 << ' ' << i << '\n';
    }
    return 0;

}