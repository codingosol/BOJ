#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    fixed(cout);
    cout.precision(3);
    while(testcase--)
    {
        vector<int> v;
        int num;
        cin >> num;
        double average;
        int total = 0;
        int temp;
        for(int i = 0; i < num; i++)
        {
            cin >> temp;
            v.push_back(temp);
            total += temp;
        }
        average = double(total) / num;
        int cnt = 0;
        for(int i = 0; i < num; i++)
        {
            if(v[i] > average)
            {
                cnt++;
            }
        }
        double perc = double(cnt) / num * 100;
        cout << perc << "%" << '\n';
    }
}