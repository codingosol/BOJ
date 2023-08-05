#include <iostream>

using namespace std;

int main(void)
{
    int n,m;
    cin >> n >> m;
    int arr[100001];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int start, end;
    start = 1;
    end = 1;
    int len = 987654321;
    int sum = arr[1];
    while(start <= end && end <= n)
    {
        if(sum < m)
        {
            end++;
            sum += arr[end];
        }
        else
        {
            len = min(len, end - start + 1);
            sum -= arr[start];
            start++;
        }
    }
    if(len == 987654321)
    {
        cout << "0\n";
        return 0;
    }
    else {
        cout << len << '\n';
        return 0;
    }
}