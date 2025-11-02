#include <bits/stdc++.h>
using namespace std;

// 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 1; // 사과 위치
    }

    int L;
    cin >> L;

    map<int, char> turns;
    for(int i = 0; i < L; i++){
        int t;
        char d;
        cin >> t >> d;
        turns[t] = d;
    }

    deque<pair<int,int>> snake;
    snake.push_back({0, 0}); // 뱀 시작 위치

    int time = 0;
    int dir = 0; // 0:동, 1:남, 2:서, 3:북

    while(true){
        time++;

        int y = snake.back().first;
        int x = snake.back().second;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 벽 + 몸에 부딪힘 체크
        if(ny < 0 || ny >= N || nx < 0 || nx >= N ||
           find(snake.begin(), snake.end(), make_pair(ny, nx)) != snake.end()){
            break;
        }

        snake.push_back({ny, nx});

        if(board[ny][nx] == 1){
            board[ny][nx] = 0; // 사과 먹으면 꼬리 그대로
        } 
        else {
            snake.pop_front(); // 사과 없으면 꼬리 줄임
        }
        
        if(turns.count(time)){
            if(turns[time] == 'D') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
        }
    }

    cout << time << "\n";
    return 0;
}
