#include <iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x > 0) {
    cout << (y > 0 ? 1 : 4);
  } else {
    cout << (y > 0 ? 2 : 3);
  }
}