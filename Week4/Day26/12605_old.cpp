#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

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
        string temp;
        temp.resize(26);
        int size = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == ' ' || j + 1 == str.length()) // 빈자리를 만난다면
            {
                stk.push(temp);
                temp.erase(0,size - 1);
                size = 0;
            }
            else
            {
                temp[size] = str[j];
                size++;
            }
        } // 쪼개서 v에 저장
        cout << "Case #" << i + 1 << ": ";
        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << "\n";
    }

}