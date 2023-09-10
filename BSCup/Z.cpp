#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    map<string,int> m;
    /*
    Never gonna give you up
    Never gonna let you down
    Never gonna run around and desert you
    Never gonna make you cry
    Never gonna say goodbye
    Never gonna tell a lie and hurt you
    Never gonna stop
    */
    m["Never gonna give you up"] = 1;
    m["Never gonna let you down"] = 1;
    m["Never gonna run around and desert you"] = 1;
    m["Never gonna make you cry"] = 1;
    m["Never gonna say goodbye"] = 1;
    m["Never gonna tell a lie and hurt you"] = 1;
    m["Never gonna stop"] = 1;
    string str;
    int n;
    cin >> n;
    bool flag = true; 
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin,str);
        //cout << str << '\n';
        if(m.find(str) == m.end()) // 기존에 없던 공약이면
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
    return 0;
}