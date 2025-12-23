#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int graph[101][101];
int maxSize = 0;
int newSize = 0;
bool visited[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void DFS(int startX,int startY){
    visited[startX][startY] = true;
    newSize++;
    for(int i=0;i<4;i++){
        int nx = startX + dx[i];
        int ny = startY + dy[i];

        if((0 < nx && nx <= n) && (0 < ny && ny <= m) && !visited[nx][ny] && graph[nx][ny] == 1){
            DFS(nx,ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i=0;i<k;i++){
        int r,c;
        cin >> r >> c;
        graph[r][c] = 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(graph[i][j] == 1 && !visited[i][j]){
                newSize = 0;
                DFS(i,j);
                if(newSize > maxSize) {
                    maxSize = newSize;
                }
            }
        }
    }

    cout << maxSize << "\n";


    return 0;
}
