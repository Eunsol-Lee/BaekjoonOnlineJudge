#include <iostream>

using namespace std;

int main() {
  int T;
  int N, W;

  cin >> T;
  for (int t = 0; t < T; t ++) {

    int value[10000][2];
    int status[10000][2][2] = {0};
    int result;

    cin >> N >> W;
    for (int i = 0; i < N; i ++) {
      cin >> value[i][0];
    }
    for (int i = 0; i < N; i ++) {
      cin >> value[i][1];
    }

    status[0][0][0] = 0;
    status[0][0][1] = 1;
    status[0][1][0] = 1;
    status[0][1][1] = value[0][0] + value[0][1] <= W ? 1 : 2;
 
    for (int i = 1; i < N; i ++) {
      status[i][0][0] = min(status[i-1][1][1], status[i-1][0][1] + 1, status[i-1][1][0] + 1);
      status[i][0][1] = min(status[i-1][1][1] + 1, status[i-1][1][0] + (value[i][1] + value[i - 1][1] <= W ? 1 : 2));
      status[i][1][0] = min(status[i-1][1][1] + 1, status[i-1][0][1] + (value[i][1] + value[i - 1][0] <= W ? 1 : 2));
      status[i][1][1] = min(status[i][0][0] + (value[i][0] + value[i][1] <= W ? 1 : 2), status[i][0][1] + 1, status[i][1][0] + 1);
    }

    result = min(status[i][1][1], status[i][1][0] + )
  }
}