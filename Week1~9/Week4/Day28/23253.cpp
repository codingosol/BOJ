#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, num_file;
    cin >> n >> num_file; // 교과서 수와 더미 수
    // 교과서 번호가 높은 것 아래에 낮은게 깔리면 불가능해짐
    vector<stack<int>> v;
    v.resize(num_file);
    int num;
    int temp;
    for(int i = 0; i < num_file; i++)
    {
        cin >> num; // 현재 더미에 쓸 교과서 수
        for(int j = 0; j < num; j++)
        {
            cin >> temp;
            if(v[i].empty()) // 비었을 경우
            {
                v[i].push(temp);
            }
            else if(v[i].top() > temp) // 비지 않고 아래 값이 위 값보다 클 때
            {
                v[i].push(temp);
            }
            else // 비지 않고 위 값이 아래 값보다 클 때 -> 실패
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}