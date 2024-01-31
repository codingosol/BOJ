#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0)
        {
            if(pq.empty())
            {
                cout << "0\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }
    return 0;
}