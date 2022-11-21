#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

#define MAXN ((int)1e4)

int M, T, N;//배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];

int arrived[MAXN + 10];

queue<pair<int, int> > waiting_left; //(손님 인덱스, 도착 시간)
queue<pair<int, int> > waiting_right;
queue<int> ferry;

void InputData() {
	cin >> M >> T >> N;
	for (int i = 0; i < N; i++) {
		cin >> AT[i] >> SIDE[i];
		if (SIDE[i] == "left")
		{
		    waiting_left.push(make_pair(i, AT[i]));
		}
		else
		{
		    waiting_right.push(make_pair(i, AT[i]));
		}
	}
}

void OutputData() {
	for (int i = 0; i < N; i++) {
		cout << arrived[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	InputData();//입력받는 부분
	
	//여기서부터 작성
	int curTime = 0;
	bool isLeft = true;
	bool move = false;
	while (1)
	{
	    if (curTime != 0 && ferry.empty() && waiting_left.empty() && waiting_right.empty())
	    {
	        break;
	    }
	    
	    if (isLeft)
	    {
	        while (!ferry.empty())
	        {
	            arrived[ferry.front()] = curTime;
	            ferry.pop();
	            move = false;
	        }
	        
	        int isTaken = false;
	        while (!waiting_left.empty())
	        {
	            if (curTime < waiting_left.front().second)
	            {
	                if (isTaken)
	                {
	                    move = true;
	                }
	                break;
	            }
	            
	            if (ferry.size() == M)
	            {
	               move = true;
	               break;
	            }
	            
	            ferry.push(waiting_left.front().first);
	            waiting_left.pop();
	            isTaken = true;
	            if (waiting_left.empty())
	            {
	                move = true;
	            }
	        }

	        if (curTime >= waiting_right.front().second)
	        {
	            move = true;
	        }
	    }
	    else if (!isLeft)
	    {
	        while (!ferry.empty())
	        {
	            arrived[ferry.front()] = curTime;
	            ferry.pop();
	            move = false;
	        }
	        
	        int isTaken = false;
	        while (!waiting_right.empty())
	        {
	            if (curTime < waiting_right.front().second)
	            {
	                if (isTaken)
	                {
	                    move = true;
	                }
	                break;
	            }
	            
	            if (ferry.size() == M)
	            {
	               move = true;
	               break;
	            }
	            
	            ferry.push(waiting_right.front().first);
	            waiting_right.pop();
	            isTaken = true;
	            if (waiting_right.empty())
	            {
	                move = true;
	            }
	        }
	        
	        if (curTime >= waiting_left.front().second)
	        {
	            move = true;
	        }
	    }
	    
	    if (move)
	    {
	        isLeft = !isLeft;
	        curTime += T;
	    }
	    else
	    {
	        curTime++;
	    }
	}

	OutputData();//출력하는 부분
	return 0;
}