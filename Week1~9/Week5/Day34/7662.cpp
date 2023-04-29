#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int n;
    char oper;
    int temp;
    for(int i = 0; i < testcase; i++)
    {
        multiset<int> dq;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> oper >> temp;
            if(oper == 'D')
            {
                if(dq.empty())
                {
                    continue;
                }
                else if(temp == 1) // 최댓값 삭제 연산
                {
                    auto iter = dq.end();
                    iter--;
                    dq.erase(iter);
                }
                else if(temp == -1) // 최솟값 삭제 연산
                {
                    dq.erase(dq.begin());
                }
            }
            else if(oper == 'I') // 삽입 연산
            {
                dq.insert(temp);
            }
        }
        if(dq.empty())
        {
            cout << "EMPTY\n";
        }
        else {
            auto iter = dq.end();
            iter--;
            cout << *iter << " " << *dq.begin() << "\n";
        }
    }
    return 0;
}