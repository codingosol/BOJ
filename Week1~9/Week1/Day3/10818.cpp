#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int max = -1000000;
  int min = 1000000;
  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    if (num > max)
      max = num;
    if (num < min)
      min = num;
  }
  cout << min << " " << max << "\n";
  return 0;
}