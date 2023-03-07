#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    int n ;
    cin >> n;
    int shirt, pant;
    string name, type;
    for(int i = 0; i < n; i++)
    {
        unordered_map<string,string> up;
        unordered_map<string,string> down;
        cin >> shirt;
        for(int j = 0; j < shirt; j++)
        {
            cin >> name >> type;
            up.insert({name,type});
        }
        

    }
}