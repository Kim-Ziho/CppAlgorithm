#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int y;
  int x;
};

int N; //격자크기
int K; //도시 수
int U; //높이차 U이상
int D; //높이차 D이하
int arr[8][8];
int maxi;

void input() {
  cin >> N >> K >> U >> D;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      cin >> arr[y][x];
    }
  }
}

void bfs(Node start) {
  int count = 1;
  queue<Node> q;
  q.push(start);
  int value = arr[start.y][start.x];

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {

    }
  }

}

int main() {
  freopen("우리는하나.txt", "r", stdin);
  input();
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      bfs({ y, x });
    }
  }

  cout << maxi << endl;

  return 0;
}