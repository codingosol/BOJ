#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string temp;
    vector<string> v;
    map<string,int> dic;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        dic[temp] = 1;
    }
    // 단어 중복 생각해야함
    char first = '0', last = '0'; // 기본 문자 0으로 저장
    for(int i = 0; i < n; i++)
    {
        if(n == 1)
        {
            continue;
        }
        if(v[i] == "?")
        {
            // 앞글자 뒷글자 저장
            if(i == 0) // 앞글자 생각할필요 X
            {
                last = last = v[i+1][0];
            }
            else if(i != n-1)
            {
                first = v[i-1][v[i-1].length()-1];
                last = v[i+1][0];
            }
            else { // 뒷글자 생각할필요 X
                first = v[i-1][v[i-1].length()-1];
            }
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        if(dic.find(temp) != dic.end()) // 이미 있다면
        {
            continue;
        }
        if(first == '0' && temp[temp.length()-1] == last)
        {
            cout << temp << '\n';
            break;
        }
        else if(last == '0' && temp[0] == first)
        {
            cout << temp << '\n';
            break;
        }
        else if(temp[0] == first && temp[temp.length()-1] == last)
        {
            cout << temp << '\n';
            break;
        }
        else if(first == '0' && last == '0')
        {
            cout << temp << '\n';
            break;
        }
    }
    return 0;
}