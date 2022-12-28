#include<bits/stdc++.h>
#include<easyx.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
#pragma comment(lib,"winmm.lib")
const int maxn = 3005;
int x, y, a[maxn][maxn];
int u[5], v[5], st[maxn];
bool vis[maxn][maxn];
signed main() {
	srand(time(NULL));
	cin >> x >> y;
	initgraph(x * 100, y * 100);
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			a[i][j] = rand() % 4 + 1;
		}
	}//1:red  2:blue   3:yellow  4.green
	int num = 0, score = 0;
	while (1) {
		if (num == 3) {
			if (st[1]==st[2]&&st[1]==st[3]&&st[2]==st[3]) {
				a[u[1]][v[1]] = a[u[2]][v[2]] = a[u[3]][v[3]] = -1;
				score += 10;
//				system("cls");
//				printf("%d", score);
			}
			else {
				a[u[1]][v[1]] = st[1];
				a[u[2]][v[2]] = st[2];
				a[u[3]][v[3]] = st[3];
				vis[u[1]][v[1]] = 0;
				vis[u[2]][v[2]] = 0;
				vis[u[3]][v[3]] = 0;
			}
			num = 0;
		}
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				int h1 = (i - 1) * 100;
				int w1 = (j - 1) * 100;
				int h2 = i * 100;
				int w2 = j * 100;
				if (a[i][j] == -1) {
					setfillcolor(BLACK);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 0) {
					setfillcolor(WHITE);
					fillrectangle(h1, w1, h2, w2);
				}else if (a[i][j] == 1) {
					setfillcolor(RED);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 2) {
					setfillcolor(BLUE);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 3) {
					setfillcolor(YELLOW);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 4) {
					setfillcolor(GREEN);
					fillrectangle(h1, w1, h2, w2);
				}
			}
		}
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		switch (m.message) {
		case WM_LBUTTONDOWN:
			if (!vis[m.x / 100+1][m.y / 100+1]) {
				u[++num] = m.x / 100+1;
				v[num] = m.y / 100+1;
				cout << u[num] << ' ' << v[num] << endl;
				vis[m.x / 100+1][m.y / 100+1] = 1;
				st[num] = a[u[num]][v[num]];
				a[u[num]][v[num]] = 0;
			}
			break;
		}
	}
}