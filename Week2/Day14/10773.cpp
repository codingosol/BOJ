#include <iostream>
#include <stack>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int temp;
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == 0) {
      stk.pop();
    } else {
      stk.push(temp);
    }
  }
  long long total = 0;
  int size;
  size = stk.size();
  for (int i = 0; i < size; i++) {
    total += stk.top();
    stk.pop();
  }
  cout << total << "\n";
  return 0;
}