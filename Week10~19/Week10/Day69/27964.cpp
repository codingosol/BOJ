#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string str;
    set<string> s;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        // 끝자리 6개가 Cheese여야 치즈임
        if(str.length() < 6)
            continue;
        string cheese = str.substr(str.length() - 6);
        if(cheese != "Cheese")
            continue;
        if(s.find(str) != s.end()) // 이미 있다면
        {
            continue;
        }
        else {
            s.insert({str,1}); 
        }
    }
    if(s.size() >= 4)
        cout << "yummy\n";
    else
        cout << "sad\n";
    return 0;
}