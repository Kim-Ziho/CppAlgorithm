#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int y;
  int x;
};

int N;
int arr[100][100];
int used[100][100];
int cnt;
int max_block;
int direct_x[4] = { 0, 0, 1, -1 };
int direct_y[4] = { 1, -1, 0, 0 };

void input() {
  cin >> N;`
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        cin >> arr[y][x];
      }
    }
}

void bfs(Node start) {
  queue<Node> q;
  q.push(start);
  used[start.y][start.x] = 1;
  int count = 1;

  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    int value = arr[now.y][now.x];

    for (int i = 0; i < 4; i++) {
      int ny = now.y + direct_y[i];
      int nx = now.x + direct_x[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (used[ny][nx] == 1) continue;
      if (arr[ny][nx] != value) continue;
      used[ny][nx] = 1;
      count++;
      Node next = { ny, nx };
      q.push(next);
    }
  }
  if (count > max_block) {
    max_block = count;
  }
  if (count >= 4) {
    cnt++;
  }
}

int main() {
  freopen("뿌요뿌요.txt", "r", stdin);
  input();
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (used[y][x] == 1) continue;
      Node start = { y, x };
      bfs(start);
    }
  }

  cout << cnt << ' ' << max_block << endl;

  return 0;
}