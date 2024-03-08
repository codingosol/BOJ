#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n;
    cin >> n;
    int temp;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str == "add"){
            cin >> temp;
            if(s.find(temp) == s.end()){ // 없다면
                s.insert(temp);
            }
        }
        else if(str == "remove"){
            cin >> temp;
            if(s.find(temp) != s.end()) // 이미 있다면 삭제
            {
                s.erase(temp);
            }
        }
        else if(str == "check"){
            cin >> temp;
            if(s.find(temp) != s.end()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(str == "toggle"){
            cin >> temp;
            if(s.find(temp) != s.end()){
                s.erase(temp);
            }
            else{
                s.insert(temp);
            }
        }
        else if(str == "all"){
            for(int j = 1; j <= 20; j++)
            {
                s.insert(j);
            }
        }
        else if(str == "empty"){
            s.clear();
        }
    }
}