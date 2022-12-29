#include<bits/stdc++.h>
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>
#include<windows.h>
using namespace std;
#pragma comment(lib,"winmm.lib")
const int maxn = 3005;
int num = 0, score = 0;
int x, y, a[maxn][maxn];
int u[5], v[5], st[maxn];
bool vis[maxn][maxn];
void output();
void game();
void load() {
	initgraph(1000,500);
	IMAGE img;
	loadimage(&img,"work.png",1000,500);
	putimage(0,0,&img);
	Sleep(2000);
	closegraph();
}
void voice() {
	mciSendString("open d:\\song.mp3",NULL,0,NULL);
	mciSendString("play d:\\song.mp3",NULL,0,NULL);
}
signed main() {
	load();
	srand(time(NULL));
	while(true){
	that:;
		printf("1.开始   2.设置\n");
		char k = _getch();
		if (k == '1') {
			system("cls");
			printf("请输入地图大小（长乘宽）：\n");
			cin >> x >> y;
			system("cls");
			game();
		}
		else if (k == '2') {
			system("cls");
			printf("此游戏出自无谑工作室，其中r键可以重置地图，点击3个相同的颜色即可消除，黑色为以消除，白色为已选择,esc键回到开始处\n");
			system("pause");
			system("cls");
		}
		else {
			printf("无此操作，请重试");
			goto that;
		}
	}
}
void game(){
	initgraph(x * 50 + 20, y * 50 + 20);//1:red  2:blue   3:yellow  4.green
here:;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			a[i][j] = rand() % 4 + 1;
		}
	}
	TCHAR s[5];
	_stprintf(s, _T("%d"), score);
	outtextxy(0, y * 50 + 5, s);
	while (1) {
		//		voice();
		if (num == 3) {
			if (st[1] == st[2] && st[1] == st[3] && st[2] == st[3]) {
				a[u[1]][v[1]] = a[u[2]][v[2]] = a[u[3]][v[3]] = -1;
				score += 10;
				TCHAR s[5];
				//				cleardevice();
				_stprintf(s, _T("%d"), score);
				outtextxy(0, y * 50 + 5, s);
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
				int h1 = (i - 1) * 50;
				int w1 = (j - 1) * 50;
				int h2 = i * 50;
				int w2 = j * 50;
				if (a[i][j] == -1) {
					setfillcolor(BLACK);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 0) {
					setfillcolor(WHITE);
					fillrectangle(h1, w1, h2, w2);
				}
				else if (a[i][j] == 1) {
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
		char key;
		if (key = _kbhit()) {
			key = _getch();
			if (key == 'r') {
				memset(vis, 0, sizeof vis);
				num = 0;
				goto here;
			}
			if (key == VK_ESCAPE) {
				closegraph();
				return;
			}
		}
		ExMessage m;
		m = getmessage(EX_MOUSE | EX_KEY);
		switch (m.message) {
		case WM_LBUTTONDOWN:
			if (!vis[m.x / 50 + 1][m.y / 50 + 1]) {
				u[++num] = m.x / 50 + 1;
				v[num] = m.y / 50 + 1;
				vis[m.x / 50 + 1][m.y / 50 + 1] = 1;
				st[num] = a[u[num]][v[num]];
				a[u[num]][v[num]] = 0;
			}
			break;
		}
	}
}
void output(){
}
