#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    string str;
    set<string> unseen;
    set<string> ans;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        unseen.insert(str);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> str;
        if(unseen.find(str) != unseen.end())
        {
            ans.insert(str);
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans)
    {
        cout << i << '\n';
    }    
    return 0;
}