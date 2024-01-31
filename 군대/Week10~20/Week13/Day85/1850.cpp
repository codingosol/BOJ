#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

int_64 GCD(int_64 N, int_64 M) {
	while (1) {
		int_64 R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

int main(void)
{
    // 최대공약수 출력
    // 단, 두 수는 2^63까지 가능하므로 정수로 받을 수 없음
    // 수를 두개 받고 이걸 2진수로 변경함
    int_64 a, b;
    cin >> a >> b;
    if(a < b)
    {
        swap(a,b);
    }
    int ans = GCD(a,b);
    for (int_64 i = 0; i < ans; i++) {
		cout << 1;
	}
	cout << "\n";
    
}