#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<string,string> password;
    string str1, str2;
    for(int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        password[str1] = str2;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> str1;
        cout << password[str1] << '\n';
    }
    return 0;
}