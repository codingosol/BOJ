#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int numoffile, temp; // 교과서 더미의 수와 교과서 번호
    vector<stack<int>> v;
    cin >> n >> numoffile;
    v.resize(numoffile);
    for(int i = 0; i < numoffile; i++)
    {   
        cin >> temp; // 더미의 교과서 수
        int booknum;
        for(int j = 0; j < temp; j++)
        {
            cin >> booknum;
            v[i].push(booknum); // segfault
        }
    }
    // 이제 더미를 뒤지며 찾아야 함
    int curbook = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            if(!v[j].empty())
            {
                if(v[j].top() == curbook)
                {   
                    curbook++;
                    v[j].pop();
                    break;
                }
            }
        }
        if(curbook != i + 2)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}