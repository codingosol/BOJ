#include <iostream>

using namespace std;

int main(void) {
  fixed(cout);
  cout.precision(1);
  double w, h;
  cin >> w >> h;
  cout << w * h / 2 << '\n';
  return 0;
}