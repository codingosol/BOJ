#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int arr[100001];
  int cnt = 0;
  vector<int> v;
  vector<char> ans;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
    ans.push_back('+');
    while (!v.empty() && v.back() == arr[cnt]) // pop해야 할 원소와 만나면
    {
      v.pop_back();
      ans.push_back('-');
      cnt++;
    }
  }
  if (!v.empty())
    cout << "NO\n";
  else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}