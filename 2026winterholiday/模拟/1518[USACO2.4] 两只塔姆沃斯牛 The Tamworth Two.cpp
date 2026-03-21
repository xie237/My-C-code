#include<iostream>
#include<cstring>
using namespace std;

char matrix[10][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cx,cy,fx,fy;
    
     for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'C') {
                cx = i; cy = j;
                matrix[i][j] = '.';  // 标记为空地
            }
            else if(matrix[i][j] == 'F') {
                fx = i; fy = j;
                matrix[i][j] = '.';
            }
          }
        }
    

    int count=0;
    bool visited[10][10][4][10][10][4];
    memset(visited, false, sizeof(visited));

    int cdir=0; int fdir=0;//北0，东1，南2，西3
    
    while(true){
        if(visited[cx][cy][cdir][fx][fy][fdir]){
            cout<<0;
            return 0;
        }
        visited[cx][cy][cdir][fx][fy][fdir]=true;

        int nfx=fx; int nfy=fy;
        if(fdir==0) nfx--;
        else if(fdir==1) nfy++;
        else if(fdir==2) nfx++;
        else if(fdir==3) nfy--;
        if(nfx<0 || nfx>9 || nfy<0 || nfy>9 || matrix[nfx][nfy]=='*'){
            fdir=(fdir+1)%4;
        }else {
            fx=nfx; fy=nfy;
        }

        int ncx=cx; int ncy=cy;
        if(cdir==0) ncx--;
        else if(cdir==1) ncy++;
        else if(cdir==2) ncx++;
        else if(cdir==3) ncy--;
        if(ncx<0 || ncx>9 || ncy<0 || ncy>9 || matrix[ncx][ncy]=='*'){
            cdir=(cdir+1)%4;
        }else {
            cx=ncx; cy=ncy;
        }
        
        count++;
        
        if(cx==fx && cy==fy){
            cout<<count;
            return 0;
        }
    }
    return 0;
}
