#include <iostream>
#include <map>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int length = 1;
    int num;
    cin >> num;
    string str;
    vector<string> v;
    for(int i = 0; i < num; i++)
    {
        cin >> str;
        v.push_back(str);
    }
    while(true)
    {
        map<string,int> m;
        string temp;
        for(int i = 0; i < v.size(); i++) // 끝자리 length개만큼 잘라서 m에 넣고 중복값 판정
        {
            temp = v[i].substr(v[i].length() - length);
            if(m.find(temp) == m.end()) // 없다면
            {
                m[temp] = 1;
            }
            else {
                m[temp]++;
            }
        }
        bool flag = true;
        for(auto i : m)
        {
            if(i.second != 1)
            {
                length++;
                flag = false;
                break;
            }
        }
        if(flag)
            break;
    }
    cout << length << "\n";
}