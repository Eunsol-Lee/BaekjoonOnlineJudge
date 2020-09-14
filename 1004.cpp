#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int T;
  int N;
  int x1, x2, y1, y2, cx, cy, r;
  bool in1, in2;
  int count;
  cin >> T;

  for (int t = 0; t < T; t ++) {
    count = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> N;
    for (int i = 0; i < N; i ++) {
      cin >> cx >> cy >> r;
      in1 = (pow(x1 - cx, 2) + pow(y1 - cy, 2) > pow(r, 2)) ? false : true;
      in2 = (pow(x2 - cx, 2) + pow(y2 - cy, 2) > pow(r, 2)) ? false : true;
      count += (int)(in1 != in2);
    }
    cout << count << endl;
  }

  return 0;
}