#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define L 100
/*
ABCDGHIJKLOPQRESTUVWXYZ
ADEFGHILMNOPQRESTXYZ
*/
using namespace std;
int dp[L][L];           //dp矩阵
int path[L][L];         //dp选择的方向，斜向下为0，向右为1，向下为-1
char X[L],Y[L];        //输入的两个基因序列
int s[L][L];
char resx[L],resy[L];   //匹配出来的结果
int presx,presy;        //用于给匹配结果置值的指针


void dfs(int x,int y){  //用于回溯dp矩阵产生遍历结果
    if(x==0||y==0)
        return;
    else if(path[x][y]==0)
    {
        dfs(x-1,y-1);
        resx[presx++]=X[x-1];
        resy[presy++]=Y[y-1];
    }
    else if(path[x][y]==1)
    {
        dfs(x-1,y);
        resx[presx++]=X[x-1];
        resy[presy++]='_';
    }
    else if(path[x][y]==-1)
    {
        dfs(x,y-1);
        resx[presx++]='_';
        resy[presy++]=Y[y-1];
    }

}
int main()
{
    printf("请输入序列1：");
	scanf("%s", X);
	printf("请输入序列2：");
	scanf("%s", Y);
	int lenx = strlen(X);
	int leny = strlen(Y);
	for (int i = 0; i < lenx; i++) {
		for (int j = 0; j < leny; j++) {
			if (X[i] == Y[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                path[i+1][j+1]=0;
            }
			else if(dp[i][j+1]>dp[i+1][j])
            {
                dp[i + 1][j + 1]=dp[i][j+1];
                path[i+1][j+1]=1;
            }
            else
            {
                dp[i + 1][j + 1]=dp[i + 1][j];
                path[i+1][j+1]=-1;
            }
		}
	}
	printf("dp矩阵：\n");
	for (int i = 0; i < lenx+1; i++) {
		for (int j = 0; j < leny+1; j++) {
			printf("%3d", dp[i][j]);
		}
		printf("\n");
	}
	printf("\npath矩阵：\n");
	for (int i = 0; i < lenx+1; i++) {
		for (int j = 0; j < leny+1; j++) {
			printf("%3d", path[i][j]);
		}
		printf("\n");
	}
	dfs(lenx,leny);
	printf("%s\n",resx);
    printf("%s\n",resy);
	return 0;
}

