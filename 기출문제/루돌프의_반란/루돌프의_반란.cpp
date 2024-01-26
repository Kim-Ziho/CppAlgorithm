#include <iostream>
#include <string>
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
int ds_y[4] = { -1, 1, 0, 0 };
int ds_x[4] = { 0, 0, 1, -1 };

int get_dist(Pos t, Pos v) {
	return (t.r - v.r) ^ 2 + (t.c - v.c) ^ 2;
}

void interaction() {

}

void stun() {

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
}

void move_santa() {
	for (int i = 1; i <= P; i++) {
		if (santa[i].is_dead) continue;
		if (santa[i].stun >= turn) continue;

		int near_direct = -1;
		int near_dist = 21e8;
		for (int j = 0; j < 4; j++) {
			Pos next;
			next.r = santa[i].pos.r + ds_y[j];
			next.c = santa[i].pos.c + ds_x[j];
			if (arr[next.r][next.c] > 0) continue;
			if (next.r <= 0 || next.c <= 0 || next.r > N || next.c > N) continue;

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


		}

	}
}


void play(int m) {

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
		play(i);
		turn++;
	}

	for (int i = 1; i <= P; i++) {
		cout << santa[i].score << ' ';
	} cout << endl;
}