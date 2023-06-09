#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> arr;
    int total = 0;
    int average;
    int mid = 0;
    int temp;
    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        total += temp;
    }
    sort(arr.begin(),arr.end());
    average = total / 5;
    mid = arr[2];
    cout << average << '\n' << mid << '\n';
    return 0;
}