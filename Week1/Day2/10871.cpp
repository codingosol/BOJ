#include <iostream>
using namespace std;

int main(void) {
  int arr[10000];
  int num;
  cin >> num;
  int N;
  cin >> N;
  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < num; i++) {
    if (arr[i] < N) {
      cout << arr[i] << " ";
    }
  }
  cout << "\n";
  return 0;
}