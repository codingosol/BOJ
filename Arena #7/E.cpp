#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> blackhole;
vector<pair<int, int>> planet;
bool done[200001];
int n, m;

bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; }

bool solve(pair<int, int> p, int power) {
  int pos = p.first;
  int w = p.second;
  // pos와 가장 가까운 블랙홀 위치를 이분탐색해야함
  int mindist = 987654321;
  int first = 0;
  int last = n;
  while (first <= last) {
    int mid = (first + last) / 2;
    if (blackhole[mid] - pos < 0) {
      if (abs(blackhole[mid] - pos) < mindist) {
        mindist = abs(blackhole[mid] - pos);
      }
      first = mid + 1;
    } else if (blackhole[mid] - pos > 0) {
      if (abs(blackhole[mid] - pos) < mindist) {
        mindist = abs(blackhole[mid] - pos);
      }
      last = mid - 1;
    } else {
      mindist = 0;
      break;
    }
  }
  // cout << "minimum dist is : " << mindist << '\n';
  if (mindist <= double(power) / w) {
    return true;
  } else
    return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fill_n(done, 200001, false);
  cin >> n >> m;
  int temp;
  int p, w;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    blackhole.push_back(temp);
  }
  for (int i = 0; i < m; i++) {
    cin >> p >> w;
    planet.push_back(make_pair(p, w));
  }
  // 만약 브루트포스 비교를 한다고 하면 200000*200000 비교를 해야함
  // 적어도 이분탐색으로 가장 가까운 블랙홀과 비교하는게 나음
  sort(blackhole.begin(), blackhole.end());
  sort(planet.begin(), planet.end(),
       cmp); // 기본 정렬이 아마도 first기준으로 오름차순 정렬
  int power = 1; // 블랙홀의 힘
  while (true) {
    bool flag = true;
    for (int i = 0; i < m;
         i++) // 모든 소행성에 대해 빨아들이기가 가능해야 탈출함
    {
      // 한 번 성공한 소행성은 다음 p에서 계산할 필요가 없음
      if (done[i]) {
        continue;
      } else {
        flag = solve(planet[i], power);
        if (flag) {
          done[i] = true;
        }
        if (!flag) {
          power++;
          break;
        }
      }
    }
    if (flag) // 모든 소행성 가능
    {
      break;
    }
  }
  cout << power << '\n';
  return 0;
}