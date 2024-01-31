#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    int n;
    int k;
    cin >> n >> k;
    deque<int> dq;
    for(int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    cout << "<";
    int temp;
    while(!dq.empty())
    {
        for(int i = 1; i < k; i++) // k번 뒤로 옮김
        {
            temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        if(dq.size() > 1) // 원소가 1개 이상이면
        {
            cout << dq.front() << ", ";
            dq.pop_front();
        }
        else // 1개면 뒤에 , 안붙임
        {
            cout << dq.front();
            dq.pop_front();
        }
    }
    cout << ">\n";
    return 0;
}