#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 1; i <=n; i++)
    {
        dq.push_back(i);
    }
    int temp;
    while(dq.size() > 1)
    {
        cout << dq.front() << " ";
        dq.pop_front(); // 맨 위 제거
        temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
    }
    cout << dq.front() << "\n";
    return 0;
}