#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int temp;
    while(true)
    {
        vector<int> v;
        for(int i = 0; i < 3; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        if(v[0] == 0 && v[1] == 0 && v[2] == 0)
        {
            break;
        }
        else if(v[0] + v[1] <= v[2])
        {
            cout << "Invalid\n";
        }
        else if(v[0] == v[1] && v[0] == v[2])
        {
            cout << "Equilateral\n";
        }
        else if(((v[0] == v[1]) && (v[0] != v[2])) || ((v[1] == v[2]) && (v[1] != v[0])) || ((v[0] == v[2]) && (v[0] != v[1])))
        {
            cout << "Isosceles\n";
        }
        else
        {
            cout << "Scalene\n";
        }
    }
    return 0;
}