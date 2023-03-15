#include <iostream>
#include <map>

using namespace std;

typedef long long int_64;

int main(void)
{
    map<int_64,int_64> m;
    int n;
    cin >> n;
    int_64 temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(m.find(temp) == m.end()) // 처음 들어오는 수라면
        {
            m[temp] = 1;
        }
        else {
            m[temp]++; // 보유 수 증가
        }
    }
    int_64 max = 0;
    int_64 index = 5000000000000000000;
    for(auto i : m)
    {
        if(i.second > max) // 가지고 있는 수가 더 크면
        {
            max = i.second;
            index = i.first;
        }
        else if(i.second == max) // 같으면
        {
            if(i.first < index)
                index = i.first;
        }
    }
    cout << index << "\n";
    return 0;

}