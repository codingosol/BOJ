#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n ;
    cin >> n;
    int num;
    string name, type;
    // 옷을 입을 수 있는 경우의 수는 
    // type으로 하는 조합임
    // 단, 알몸일 수는 없으므로 전부 입지 않을 수는 없음
    for(int i = 0; i < n; i++)
    {
        map<string,int> m;
        cin >> num;
        for(int j = 0; j < num; j++) // 옷의 수 입력
        {
            cin >> name >> type;
            if(m.find(type) == m.end())
            {
                m.insert({type,1});
            }
            else
            {
                m.find(type)->second++;
            }

        }
        int ans = 1;
        for(auto k : m)
        {
            ans *= (k.second + 1);
        }
        ans--;
        cout << ans << "\n";
    }
    return 0;
}