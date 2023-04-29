#include <iostream>
using namespace std;

int main(void) {
  string str;
  int cnt = 0;
  getline(cin, str);
  if (str.empty())
    cout << "0\n";
  else {
    cnt++;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == ' ')
        cnt++;
    }
    if (str[0] == ' ')
      cnt--;
    if (str[str.length() - 1] == ' ')
      cnt--;
    cout << cnt << "\n";
  };
  return 0;
}