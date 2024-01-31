#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;
int n;

int main(void)
{
    cin >> n;
    vector<pair<int_64,int_64>> v;
    int_64 a, b;
    int_64 fa, fb;
    cin >> fa >> fb;
    fixed(cout);
    cout.precision(1);
    v.push_back({fa,fb});
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v.push_back({a,b});
    }
    v.push_back({fa,fb});
    double area = 0;
    double temp1 = 0;
    double temp2 = 0;
    for(int i = 0; i < v.size() - 1; i++)
    {
        temp1 = v[i].first * v[i+1].second;
        temp2 = v[i].second * v[i+1].first;
        area += temp1;
        area -= temp2;
    }
    area /= 2;
    cout << abs(area) << '\n';
    return 0;
}