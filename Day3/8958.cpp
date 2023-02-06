#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int testcase;
  cin >> testcase;
  string str;
  for (int i = 0; i < testcase; i++) {
    cin >> str;
    int streak = 1;
    int score = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'O') {
        score += streak;
        streak++;
      } else if (str[i] == 'X') {
        streak = 1;
      }
    }
    cout << score << "\n";
  }
  return 0;
}