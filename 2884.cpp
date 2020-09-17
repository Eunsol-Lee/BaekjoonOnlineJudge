#include <iostream>
using namespace std;

int main() {
  int H, M;
  int newH, newM;
  cin >> H >> M;
  newM = M - 45 < 0 ? M + 15 : M - 45;
  newH = M - 45 < 0 ? H == 0 ? 23 : H - 1: H;
  cout << newH << ' ' << newM;

}