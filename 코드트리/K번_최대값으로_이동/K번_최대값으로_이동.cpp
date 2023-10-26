#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int y;
  int x;

  bool operator<(const Node& n) const {
    if (y == n.y) {
      return x > n.x;
    }
    return y > n.y;
  }
};

int grid[101][101];
int K;
int N;
int directx[4] = { 0, 1, 0, -1 };
int directy[4] = { -1, 0, 1, 0 };

int main() {
  freopen("K번_최대값으로_이동.txt", "r", stdin);
  cin >> N >> K;
  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= N; x++) {
      cin >> grid[y][x];
    }
  }
  int sy, sx;
  cin >> sy >> sx;

  queue<Node> q;

  for (int i = 0; i < K; i++) {
    int used[101][101] = { 0 };
    priority_queue<Node> pq;
    q.push({ sy, sx });
    int maxi = 0;

    while (!q.empty()) {
      Node now = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = now.y + directy[i];
        int nx = now.x + directx[i];
        if (ny > N || nx > N || ny <= 0 || nx <= 0) continue;
        if (used[ny][nx]) continue;
        if (grid[sy][sx] <= grid[ny][nx]) continue;
        used[ny][nx] = 1;
        q.push({ ny, nx });
        if (grid[ny][nx] > maxi) {
          maxi = grid[ny][nx];
          pq = priority_queue<Node>();
          pq.push({ ny, nx });
        }
        if (grid[ny][nx] == maxi) {
          pq.push({ ny, nx });
        }
      }
    }

    if (pq.empty()) break;
    Node next = pq.top();
    if (next.y == sy && next.x == sx) break;
    else {
      sy = next.y;
      sx = next.x;
    }
  }

  cout << sy << ' ' << sx << endl;
}