#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    map<string,int> m;
    while(n--)
    {
        cin >> str;
        if(str == "ENTER") // 새로운 사람이 들어왔으므로 비움
        {
            m.clear();
        }
        else {
            if(m.find(str) != m.end()) // 이미 인사한 사람이라면
            {
                continue;
            }
            else {
                m[str] = 1;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}