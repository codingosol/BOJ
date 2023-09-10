#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    int_64 n, m;
    int_64 t, s;
    cin >> n >> m; // 집에서 하는데 걸리는 시간과 독서실에서 하는데 걸리는 시간
    cin >> t >> s; // 이동하는데 걸리는 시간과 8시간 일하고 난 뒤의 수면시간
    // 따라서 이 문제는 집에서 계속 하는 경우 vs 독서실로 가서 하고 집와서 자면서 하는 경우
    // 독서실에 가서 하는 경우는 한번 잘 때마다 왕복해야 하므로 이를 생각해야 함
    int_64 Zip = n + ((n-1) / 8) * s; // 과제하는데 걸리는 시간 + 수면시간(만약 딱 맞춰 끝난다면 잘 필요 없음)
    int_64 Dok = m + ((m-1) / 8) * (t*2+s) + t; // 과제하는데 걸리는 시간 + 왕복시간(최초 방문은 왕복이 아니므로 +1) + 수면시간
    if(Zip < Dok)
    {
        cout << "Zip\n";
        cout << Zip << '\n';
    }
    else {
        cout << "Dok\n";
        cout << Dok << '\n';
    }
    return 0;
}