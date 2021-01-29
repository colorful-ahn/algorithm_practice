//
//  main.cpp
//  backjun
//
//  Created by kyung rok An on 2021/01/29.
//
#include<iostream>
using namespace std;

const int MAX = 100;
 
int arr[MAX][MAX], arr2[MAX][MAX];
int result[MAX][MAX];
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int N, M, K;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
                 for (int j = 0; j < M; j++)
                         cin >> arr[i][j];
 
        cin >> M >> K;
        for (int i = 0; i < M; i++)
                 for (int j = 0; j < K; j++)
                         cin >> arr2[i][j];
 
        for (int i = 0; i < N; i++)
                 for (int j = 0; j < K; j++)
                         for (int k = 0; k < M; k++)
                                 result[i][j] += (arr[i][k] * arr2[k][j]);
 
        for (int i = 0; i < N; i++)
        {
                 for (int j = 0; j < K; j++)
                         cout << result[i][j] << " ";
                 cout << "\n";
        }
        return 0;
}

