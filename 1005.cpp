#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int T, N, K;
  int D[1000];
  int in[1000];
  bool m[1000][1000];
  int value[1000];
  int X, Y, W;
  queue<int> q;

  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
      cin >> D[i];
      for (int j = 0; j < N; j++)
      {
        m[i][j] = false;
      }
      in[i] = 0;
      value[i] = 0;
    }

    for (int i = 0; i < K; i++)
    {
      cin >> X >> Y;
      m[X - 1][Y - 1] = true;
      in[Y - 1]++;
    }

    cin >> W;
    W--;

    for (int i = 0; i < N; i++)
    {
      if (in[i] == 0)
      {
        q.push(i);
        value[i] = D[i];
      }
    }

    while (!q.empty())
    {
      int c = q.front();
      q.pop();
      for (int i = 0; i < N; i++)
      {
        if (m[c][i])
        {
          value[i] = max(value[i], value[c] + D[i]);
          in[i]--;
          if (in[i] == 0)
          {
            q.push(i);
          }
        }
      }
    }
    cout << value[W] << endl;
  }
}