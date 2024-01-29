#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Pos {
	int r, c;
};

struct Santa {
	Pos pos;
	int score;
	int stun;
	bool is_dead;
} santa[31];

Pos rudolph;

int arr[51][51];
int N, M, P, C, D, turn;
int dr_y[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dr_x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int ds_y[4] = { -1, 0, 1, 0 };
int ds_x[4] = { 0, 1, 0, -1 };

void print_arr() {
	cout << "------------------" << endl;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << arr[y][x] << ' ';
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}

int get_dist(Pos t, Pos v) {
	return pow((t.r - v.r), 2) + pow((t.c - v.c), 2);
}

void interaction(int idx, int dy, int dx) {
	int r = santa[idx].pos.r;
	int c = santa[idx].pos.c;
	if (r <= 0 || c <= 0 || r > N || c > N) {
		santa[idx].is_dead = true;
		return;
	}
	if (arr[r][c] > 0) {
		int next = arr[r][c];
		santa[next].pos.r += dy;
		santa[next].pos.c += dx;
		interaction(next, dy, dx);
	}
	arr[r][c] = idx;
}

void stun(int idx) {
	santa[idx].stun = turn + 1;
}

void move_rudolph() {
	int near_idx = -1;
	int near_dist = 21e8;
	for (int i = 1; i <= P; i++) {
		if (santa[i].is_dead) continue;

		int dist = get_dist(santa[i].pos, rudolph);
		if (dist < near_dist) {
			near_dist = dist;
			near_idx = i;
		}
		else if (dist == near_dist) {
			if (santa[i].pos.r > santa[near_idx].pos.r) {
				near_idx = i;
			}
			else if (santa[i].pos.r == santa[near_idx].pos.r) {
				if (santa[i].pos.c > santa[near_idx].pos.c) {
					near_idx = i;
				}
			}
		}
	}
	int near_direct = -1;
	near_dist = 21e8;
	for (int i = 0; i < 8; i++) {
		Pos next;
		next.r = rudolph.r + dr_y[i];
		next.c = rudolph.c + dr_x[i];
		int dist = get_dist(next, santa[near_idx].pos);
		if (dist < near_dist) {
			near_dist = dist;
			near_direct = i;
		}
	}

	Pos moved = { rudolph.r + dr_y[near_direct], rudolph.c + dr_x[near_direct]};
	if (arr[moved.r][moved.c] > 0) {
		int idx = arr[moved.r][moved.c];
		santa[idx].score += C;
		santa[idx].pos.r += C * dr_y[near_direct];
		santa[idx].pos.c += C * dr_x[near_direct];
		interaction(idx, dr_y[near_direct], dr_x[near_direct]);
		stun(idx);
	}
	arr[rudolph.r][rudolph.c] = 0;
	rudolph = moved;
	arr[rudolph.r][rudolph.c] = -1;

	int bug = 1;
}

void move_santa() {
	for (int i = 1; i <= P; i++) {
		if (santa[i].is_dead) continue;
		if (santa[i].stun >= turn) continue;

		int near_direct = -1;
		int near_dist = get_dist(santa[i].pos, rudolph);
		for (int j = 0; j < 4; j++) {
			Pos next;
			next.r = santa[i].pos.r + ds_y[j];
			next.c = santa[i].pos.c + ds_x[j];
			if (next.r <= 0 || next.c <= 0 || next.r > N || next.c > N) continue;
			if (arr[next.r][next.c] > 0) continue;

			int dist = get_dist(next, rudolph);
			if (dist < near_dist) {
				near_dist = dist;
				near_direct = j;
			}
		}
		if (near_direct < 0) continue;

		Pos moved = { santa[i].pos.r + ds_y[near_direct], santa[i].pos.c + ds_x[near_direct] };
		if (moved.r == rudolph.r && moved.c == rudolph.c) {
			santa[i].score += D;
			int dy = ds_y[near_direct] * -1;
			int dx = ds_x[near_direct] * -1;
			moved.r += dy * D;
			moved.c += dx * D;

			arr[santa[i].pos.r][santa[i].pos.c] = 0;
			santa[i].pos = moved;
			interaction(i, dy, dx);
			stun(i);
		}
		else {
			arr[santa[i].pos.r][santa[i].pos.c] = 0;
			santa[i].pos = moved;
			arr[santa[i].pos.r][santa[i].pos.c] = i;
		}
	}
}

void play() {
	print_arr();
	move_rudolph();
	print_arr();
	move_santa();
}

int main() {
	freopen("루돌프의_반란.txt", "r", stdin);

	cin >> N >> M >> P >> C >> D;
	cin >> rudolph.r >> rudolph.c;
	arr[rudolph.r][rudolph.c] = -1;
	for (int i = 0; i < P; i++) {
		int idx;
		cin >> idx;
		cin >> santa[idx].pos.r >> santa[idx].pos.c;
		santa[idx].score = 0;
		santa[idx].stun = 0;
		santa[idx].is_dead = false;
		arr[santa[idx].pos.r][santa[idx].pos.c] = idx;
	}

	turn = 1;
	for (int i = 1; i <= M; i++) {
		play();
		turn++;
		for (int j = 1; j <= P; j++) {
			if (santa[j].is_dead) continue;
			santa[j].score += 1;
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << santa[i].score << ' ';
	} cout << endl;
}