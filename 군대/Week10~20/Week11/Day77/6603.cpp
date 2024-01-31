#include <iostream>
#include <vector>

using namespace std;

int visited[14]; // 1~13

void pick(int cnt, vector<int> &p, vector<int> &v)
{
    if(cnt == 6) // 6개 모두 골랐다면 출력
    {
        for(int i = 0; i < 6; i++)
        {
            cout << v[p[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    else {
        // 총 6개를 골라야 함
        if(p.empty()) // 비었다면
        {
            for(int i = 0; i < v.size(); i++)
            {
                if(visited[i] == 0)
                {
                    visited[i] = 1;
                    p.push_back(i);
                    pick(cnt+1,p,v);
                    p.pop_back();
                    visited[i] = 0;
                }
            }
        }
        else
        {
            for(int i = p[cnt-1]; i < v.size(); i++) // 자기보다 큰 수만 탐색 -> 크기가 아닌 인덱스로 탐색해야함
            {
                if(visited[i] == 0)
                {
                    visited[i] = 1;
                    p.push_back(i);
                    pick(cnt+1,p,v);
                    p.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
}

int main(void)
{
    int n;
    while(true)
    {
        cin >> n;
        if(n == 0)
            break;
        else
        {
            vector<int> v;
            int temp;
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                v.push_back(temp);
            }
            vector<int> p;
            pick(0,p,v);
            cout << '\n';
        }
    }
}