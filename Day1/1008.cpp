#include <iostream>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout.precision(10);
	cout << double(a) / double(b) << "\n";
	return 0;
}