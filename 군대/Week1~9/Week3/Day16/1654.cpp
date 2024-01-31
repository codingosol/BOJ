#include <iostream>
#include <vector>
using namespace std;

#define INF 2147483648;
typedef long long int_64;

int main(void) {
  int k, n;
  cin >> k >> n;
  int temp;
  vector<int_64> v;
  for (int i = 0; i < k; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  // 입력
  // 브루트포스하면 시간초과 날듯 근데 걍 해봄
  // 벡터 내 최솟값에서 1씩 --하면서 처음으로 k값을 만족하는 친구 찾으면 되지
  // 않을까? 당연히 안됐다 이분탐색으로 바꾼다.
  //  N개보다 많이 만드는 것도 N개를 만드는 것에 포함!!!
  int_64 max = 0;
  int_64 min = 1;
  for (int i = 0; i < k; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  } // 이분탐색을 위해 최솟값과 최댓값 구해줌
  int_64 mid;
  int_64 max_length = 0;
  while (min <= max) {
    mid = (min + max) / 2;
    int cnt = 0;
    for (int i = 0; i < k; i++) // 여기서 n개의 랜선이 되는지 구함
    {
      cnt += v[i] / mid;
    }
    if (cnt >= n) // 개수가 크거나 같으면 길이가 길어져야 함
    {
      min = mid + 1;
      if (mid > max_length)
        max_length = mid;
    } else if (cnt < n) // 개수가 모자랄 경우에는 길이가 너무 길다는 뜻
    {
      max = mid - 1;
    }
  }
  cout << max_length << "\n";
  return 0;
}