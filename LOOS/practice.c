// #include <stdio.h>
// #include <stdlib.h>
// #define N 8
// int board[N];
// int solution = 0;
// // Check whether placing queen at (row, col) is safe
// int isSafe(int row, int col)
// {
//  for (int i = 0; i < row; i++)
//  {
//  if (board[i] == col || abs(board[i] - col) == abs(i - row))
//  return 0;
//  }
//  return 1;
// }
// // Print board
// void printBoard()
// {
//  printf("\nSolution %d:\n", ++solution);
//  for (int i = 0; i < N; i++)
//  {
//  for (int j = 0; j < N; j++)
//  {
//  if (board[i] == j)
//  printf(" Q ");
//  else
//  printf(" . ");
//  }
//  printf("\n");
//  }
// }
// void solve(int row)
// {
//  if (row == N)
//  {
//  printBoard();
//  return;
//  }
//  for (int col = 0; col < N; col++)
//  {
//  if (isSafe(row, col))
//  {
//  board[row] = col;
//  solve(row + 1);
//  }
//  }
// }
// int main()
// {
//  solve(0);
//  printf("\nTotal Distinct Solutions = %d\n", solution);
//  return 0;
// }
// #include<stdio.h>
// int main()
// {
// int graph[10][10],queue[20],visited[10]={0};
// int n,i,j,start,front=0,rear=0;
// printf("Enter number of vertices: ");
// scanf("%d",&n);
// printf("Enter adjacency matrix:\n");
// for(i=0;i<n;i++)
// for(j=0;j<n;j++)
// scanf("%d",&graph[i][j]);
// printf("Enter starting vertex: ");
// scanf("%d",&start);
// visited[start]=1;
// queue[rear++]=start;
// printf("BFS Traversal: ");
// while(front<rear)
// {
// int v=queue[front++];
// printf("%d ",v);
// for(i=0;i<n;i++)
// {
// if(graph[v][i] && !visited[i])
// {
// visited[i]=1;
// queue[rear++]=i;
// }
// }
// }
// return 0;}