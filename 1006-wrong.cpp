#include <iostream>

using namespace std;

int main() {
  int T;
  int N, W;

  cin >> T;
  for (int t = 0; t < T; t ++) {

    int value[10000][2];
    int status[4][10001][3] = {0}; // 11 10 01 00
    int result;

    cin >> N >> W;
    for (int i = 0; i < N; i ++) {
      cin >> value[i][0];
    }
    for (int i = 0; i < N; i ++) {
      cin >> value[i][1];
    }
    status[0][0][0] = value[0][0] + value[0][1] <= W ? 1 : 2;
    status[0][0][1] = 1;
    status[0][0][2] = 1;
    status[1][0][0] = 1;
    status[1][0][1] = 999999;
    status[1][0][2] = 0;
    status[2][0][0] = 1;
    status[2][0][1] = 0;
    status[2][0][2] = 999999;
    status[3][0][0] = 0;
    status[3][0][1] = 999999;
    status[3][0][2] = 999999;

    for (int k = 0; k < 4; k ++) {
      for (int i = 1; i < N; i ++) {


        status[k][i][1] = min(status[k][i - 1][0] + 1, status[k][i - 1][2] + (value[i][0] + value[i - 1][0] <= W ? 1 : 2));
        status[k][i][2] = min(status[k][i - 1][0] + 1, status[k][i - 1][1] + (value[i][1] + value[i - 1][1] <= W ? 1 : 2));
        status[k][i][0] = status[k][i - 1][0] + (value[i][0] + value[i][1] <= W ? 1 : 2);
        status[k][i][0] = min(status[k][i][0], status[k][i][1] + 1);
        status[k][i][0] = min(status[k][i][0], status[k][i][2] + 1);
        // cout << k << i << status[k][i][0] << status[k][i][1] << status[k][i][2] << endl;
      }
    }
    result = min(status[0][N - 1][0], status[1][N - 1][0] + 1);
    result = min(result, status[1][N - 1][2] + (value[0][0] + value[N - 1][0] <= W ? 1 : 2));
    result = min(result, status[2][N - 1][0] + 1);
    result = min(result, status[2][N - 1][1] + (value[0][1] + value[N - 1][1] <= W ? 1 : 2));
    result = min(result, status[3][N - 1][0] + (value[0][1] + value[N - 1][1] <= W ? 1 : 2)+ (value[0][0] + value[N - 1][0] <= W ? 1 : 2));

    cout << result << endl;
  }
}
