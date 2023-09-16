#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  double x;
  cin >> n >> x; // n은 들은 과목 수, x는 달성해야 할 평균 평점
  int p;         // 학점
  string str;    // 성적
  double temp = 0;
  double totalscore = 0; // 총 성적환산치합
  int totalp = 0;        // 총 학점
  for (int i = 0; i < n - 1; i++) {
    cin >> p >> str;
    if (str == "A+")
      temp = p * 4.5;
    else if (str == "A0")
      temp = p * 4.0;
    else if (str == "B+")
      temp = p * 3.5;
    else if (str == "B0")
      temp = p * 3.0;
    else if (str == "C+")
      temp = p * 2.5;
    else if (str == "C0")
      temp = p * 2.0;
    else if (str == "D+")
      temp = p * 1.5;
    else if (str == "D0")
      temp = p * 1.0;
    else if (str == "F")
      temp = p * 0;
    totalscore += temp;
    totalp += p;
  }
  // 이제 마지막 과목의 학점을 받음
  cin >> p;
  // 받아야 할 최종 과목의 학점을 T라고 했을 때
  // (totalscore + T * 성적) / (totalp + T) > X여야 함
  // 따라서 우리는 성적을 구해야 하므로 등식으로 전환
  // 성적 = (X * (totalp + T) - totalscore) / T가 됨
  // 평균 평점은 소수점 세번째 자리에서 버림한 값임
  double needscore =
      ((x * (totalp + p) - totalscore) / p); // 동일해지기 위해서 얻어야 할 평점
  cout << needscore << '\n';
  // 평점은 소수점 2번째 자리에서 반올림해야 함(소수점 평점은 받을 수 없으므로)
  needscore = ceil(needscore * 10) / 10;
  cout << needscore << '\n';
  double finalscore = ((needscore * p + totalscore) / (totalp + p));
  //  만약 finalscore에서 목표 평점과 동일해져 버린다면 평점을 한칸씩 올려야 함
  finalscore = ceil(finalscore * 100) / 100;
  cout << finalscore << '\n';
  bool flag = false;
  if (finalscore == x) {
    flag = true;
  }
  if (needscore == 4.5) {
    if (flag)
      cout << "impossible\n";
    else
      cout << "A+\n";
  } else if (needscore == 4.0) {
    if (flag)
      cout << "A+\n";
    else
      cout << "A0\n";
  } else if (needscore == 3.5) {
    if (flag)
      cout << "A0\n";
    else
      cout << "B+\n";
  } else if (needscore == 3.0) {
    if (flag)
      cout << "B+";
    else
      cout << "B0\n";
  } else if (needscore == 2.5) {
    if (flag)
      cout << "B0\n";
    else
      cout << "C+\n";
  } else if (needscore == 2.0) {
    if (flag)
      cout << "C+\n";
    else
      cout << "C0\n";
  } else if (needscore == 1.5) {
    if (flag)
      cout << "C0\n";
    else
      cout << "D+\n";
  } else if (needscore == 1.0) {
    if (flag)
      cout << "D+\n";
    else
      cout << "D0\n";
  } else if (needscore < 0.0) {
    if (flag) {
      cout << "D0\n";
    } else
      cout << "F\n";
  }
  return 0;
}