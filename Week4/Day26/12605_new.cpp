#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

stack<string> tokenize(string str, char delimeter)
{
    stack<string> result;
    string token;
    stringstream ss(str);
    while(getline(ss,token,delimeter))
    {
        result.push(token);
    }
    return result;
}

int main(void)
{
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string str;
        getline(cin,str); // \n을 만날 때까지 전부 받음
        
        stack<string> stk;
        stk = tokenize(str, ' ');
        cout << "Case #" << i+1 << ": ";
        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << "\n";
    }
    return 0;
}