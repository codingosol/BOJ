#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    string a, b;
    for(int i = 0; i < testcase; i++)
    {
        int n;
        cin >> n;
        map<string,int> m;
        for(int j = 0; j < n; j++) // 같은 이름의 옷은 없으므로 카테고리만 살피면 된다
        {
            cin >> a >> b;
            if(m.find(b) != m.end()){ // 이미 있는 카테고리라면
                m[b]++;
            }
            else
                m[b] = 1;   
        }
        int ans = 1;
        for(auto i : m)
        {
            ans *= (i.second + 1);
        }
        cout << ans - 1 << '\n'; // 모든 카테고리를 안 입어서 알몸이 되면 안되므로 -1;
    }
    return 0;
}