#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define MAXW (20)
#define INF (MAXW * 2000)

int N;//도로의 개수
int W;//사건의 개수
struct POS{
	int r, c;//세로, 가로
};
POS pos[MAXW+10];//사건 좌표
int ans = INF;

void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}

void DFS(int cnt, int dist, int y1, int x1, int y2, int x2)
{
    if (cnt == W)
    {
        ans = min(ans, dist);
        return;
    }
    int dist1 = abs(pos[cnt].r - y1) + abs(pos[cnt].c - x1);
    DFS(cnt + 1, dist + dist1, pos[cnt].r, pos[cnt].c, y2, x2);
    int dist2 = abs(pos[cnt].r - y2) + abs(pos[cnt].c - x2);
    DFS(cnt + 1, dist + dist2, y1, x1, pos[cnt].r, pos[cnt].c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력받는 부분

	//여기서부터 작성
    DFS(0, 0, 1, 1, N, N);

	cout << ans << "\n";//출력하는 부분
	return 0;
}