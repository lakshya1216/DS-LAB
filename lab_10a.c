#include<stdio.h>
int a[10][10],vis[10],n;
void bfs(int);
void main(){
    int i, j, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjecancy matrix elements: \n");
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &a[i][j]);
        }vis[i]=0;
    }
    printf("Enter src vertex\n");
    scanf("%d",&src);
    printf("Nodes Reachable are : ");
    bfs(src);
}
void bfs(int v){
    int q[10],f=1, r=1, u,i;
    q[r]=v;
    vis[v]=1;
    while(f<=r){
        u=q[f];
        printf("%d ",u);
        for(i=1;i<=n;i++){
            if(a[v][i]==1 && vis[i]==0){
                vis[i]=1;
                r=r+1;
                q[r]=i;
            }
        }
        f=f+1;
    }
}
