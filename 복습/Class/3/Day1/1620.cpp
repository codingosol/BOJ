#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m; // n은 포켓몬의 수, m은 맞춰야 할 문제의 수
    cin >> n >> m;
    map<int,string> p;
    map<string,int> p2;
    string str;
    for(int i = 1; i <= n; i++)
    {
        cin >> str;
        p.insert({i,str});
        p2.insert({str,i});
    }
    for(int i = 0; i < m; i++)
    {
        cin >> str;
        // 이제 이 문자열이 수인지 알파벳인지 판별
        // 첫번째 글자가 대문자이므로
        
        if(str[0] >= 'A' && str[0] <= 'Z') // 알파벳일 때
        {
            cout << p2[str] << '\n';
        }
        else { // 숫자일 때
            int temp = 0;
            for(int i = 0; i < str.size(); i++)
            {
                temp *= 10;
                temp += str[i] - 48;
            }
            cout << p[temp] << '\n';
        }
    }
    return 0;
}