#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0) // 가장 작은 값을 출력 후 제거, 비어있다면 0 출력
        {
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(temp);
        }
    }
    return 0;
}