#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN (10)

int N;
char map[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];

int dirIdx = 0;
int dirseq[4];
int dy[5] = {0, 1, 0, -1, 0};
int dx[5] = {0, 0, -1, 0, 1};

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> dirseq[i];
	}
}
int main() {
	int ans = -1;
	InputData();//입력
	
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++)
	{
	    for (int j = 0; j < N; j++)
	    {
	        visited[i][j] = -1;
	    }
	}
	
	q.push(make_pair(0, 0));
	visited[0][0] = 0;
	while (!q.empty())
	{
	    int curY = q.front().first;
	    int curX = q.front().second;
	    q.pop();
	    
	    for (int i = 0; i < 4; i++)
	    {
	        int nextY = curY + dy[dirseq[dirIdx]];
	        int nextX = curX + dx[dirseq[dirIdx]];
	        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
	        {
	            dirIdx = (dirIdx + 1) % 4;
	            continue;
	        }
	        else if (visited[nextY][nextX] >= 0)
	        {
	            continue;
	        }
	        else if (map[nextY][nextX] == '1')
	        {
	            dirIdx = (dirIdx + 1) % 4;
	            continue;
	        }
	        else
	        {
	            q.push(make_pair(nextY, nextX));
	            visited[nextY][nextX] = visited[curY][curX] + 1;
	            ans = max(ans, visited[nextY][nextX]);
	            break;
	        }
	    }
	}

	cout << ans << "\n";//출력
	return 0;
}