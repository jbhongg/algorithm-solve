package com.ssafy.hw11;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ16935 {
	static BufferedReader br;
	static BufferedWriter bw;
	static Queue<Integer> q = new LinkedList<Integer>();
	static Queue<Integer> q2 = new LinkedList<Integer>();
	static int[][] arr;
	static int[][] arr2;
	static int N, min;
	static int M;
	static int flag;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		arr2 = new int[M][N];
		if(N >= M) {
			min = M;
		}
		else {
			min = N;
		}
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<R; i++) {
			int cal = Integer.parseInt(st.nextToken());
			switch(cal) {
			case 1:
				if(flag == 0) {
					cal1(arr, 0, N, M);
				}
				else {
					cal1(arr2, 0, M, N);
				}
				break;
			case 2:
				if(flag == 0) {
					cal2(arr, 0, N, M);
				}
				else {
					cal2(arr2, 0, M, N);
				}
				break;
			case 3:
				cal3(0,N,M);
				break;
			case 4:
				cal4(0,N,M);
				break;
			case 5:
				if(flag == 0) {
					cal5(arr, N, M);
				}
				else {
					cal5(arr2, M, N);
				}
				
				break;
			case 6:
				if(flag == 0) {
					cal6(arr, N, M);
				}
				else {
					cal6(arr2, M, N);
				}
				break;
			}
		}
		if(flag==1) {
			for(int[] i : arr2) {
				for(int j : i) {
					bw.write(j +" ");
				}
				bw.write("\n");
			}
		}
		else {
			for(int[] i : arr) {
				for(int j : i) {
					bw.write(j +" ");
				}
				bw.write("\n");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}

	private static void cal6(int[][] arr, int N, int M) {
		for(int i=0; i<N/2; i++) {
			for(int j =0; j<M/2; j++) {
				q.add(arr[i][j]);
			}
		}
		for(int i=N/2; i<N; i++) {
			for(int j =0; j<M/2; j++) {
				q2.add(arr[i][j]);
				arr[i][j] = q.poll();
			}
		}
		for(int i=N/2; i<N; i++) {
			for(int j =M/2; j<M; j++) {
				q.add(arr[i][j]);
				arr[i][j] = q2.poll();
			}
		}
		for(int i=0; i<N/2; i++) {
			for(int j =M/2; j<M; j++) {
				q2.add(arr[i][j]);
				arr[i][j] = q.poll();
			}
		}
		for(int i=0; i<N/2; i++) {
			for(int j =0; j<M/2; j++) {
				arr[i][j] = q2.poll();
			}
		}
	}

	private static void cal5(int[][] arr, int N, int M) {
		for(int i=0; i<N/2; i++) {
			for(int j =0; j<M/2; j++) {
				q.add(arr[i][j]);
			}
		}
		for(int i=0; i<N/2; i++) {
			for(int j =M/2; j<M; j++) {
				q2.add(arr[i][j]);
				arr[i][j] = q.poll();
			}
		}
		for(int i=N/2; i<N; i++) {
			for(int j =M/2; j<M; j++) {
				q.add(arr[i][j]);
				arr[i][j] = q2.poll();
			}
		}
		for(int i=N/2; i<N; i++) {
			for(int j =0; j<M/2; j++) {
				q2.add(arr[i][j]);
				arr[i][j] = q.poll();
			}
		}
		for(int i=0; i<N/2; i++) {
			for(int j =0; j<M/2; j++) {
				arr[i][j] = q2.poll();
			}
		}
	}

	private static void cal4(int x, int n, int m) {
		if(x == min/2) {
			flag ^= 1;
			return;
		}
		if(flag == 0) {
			for(int i=x; i<m; i++) {
				q.add(arr[x][i]);
			}
			for(int i=x+1; i<n; i++) {
				q.add(arr[i][m-1]);
			}
			for(int i=m-2; i>=x; i--) {
				q.add(arr[n-1][i]);
			}
			for(int i=n-2; i>=x+1; i--) {
				q.add(arr[i][x]);
			}
			
			for(int i=m-1; i>=x; i--) {
				arr2[i][x] = q.poll();
			}
			for(int i=x+1; i<n; i++) {
				arr2[x][i] = q.poll();
			}
			for(int i=x+1; i<m; i++) {
				arr2[i][n-1] = q.poll();
			}
			for(int i=n-2; i>=x+1; i--) {
				arr2[m-1][i] = q.poll();
			}
		}
		else {
			for(int i=x; i<n; i++) {
				q.add(arr2[x][i]);
			}
			for(int i=x+1; i<m; i++) {
				q.add(arr2[i][n-1]);
			}
			for(int i=n-2; i>=x; i--) {
				q.add(arr2[m-1][i]);
			}
			for(int i=m-2; i>=x+1; i--) {
				q.add(arr2[i][x]);
			}
			
			for(int i=n-1; i>=x; i--) {
				arr[i][x] = q.poll();
			}
			for(int i=x+1; i<m; i++) {
				arr[x][i] = q.poll();
			}
			for(int i=x+1; i<n; i++) {
				arr[i][m-1] = q.poll();
			}
			for(int i=m-2; i>=x+1; i--) {
				arr[n-1][i] = q.poll();
			}
		}

		cal4(x+1, n-1, m-1);	
	}

	private static void cal3(int x, int n, int m) {
		if(x == min/2) {
			flag ^= 1;
			return;
		}
		if(flag == 0) {
			for(int i=x; i<m; i++) {
				q.add(arr[x][i]);
			}
			for(int i=x+1; i<n; i++) {
				q.add(arr[i][m-1]);
			}
			for(int i=m-2; i>=x; i--) {
				q.add(arr[n-1][i]);
			}
			for(int i=n-2; i>=x+1; i--) {
				q.add(arr[i][x]);
			}
			
			for(int i=x; i<m; i++) {
				arr2[i][n-1] = q.poll();
			}
			for(int i=n-2; i>=x; i--) {
				arr2[m-1][i] = q.poll();
			}
			for(int i=m-2; i>=x; i--) {
				arr2[i][x] = q.poll();
			}
			for(int i=x+1; i<n-1; i++) {
				arr2[x][i] = q.poll();
			}
		}
		else {
			for(int i=x; i<n; i++) {
				q.add(arr2[x][i]);
			}
			for(int i=x+1; i<m; i++) {
				q.add(arr2[i][n-1]);
			}
			for(int i=n-2; i>=x; i--) {
				q.add(arr2[m-1][i]);
			}
			for(int i=m-2; i>=x+1; i--) {
				q.add(arr2[i][x]);
			}
			
			for(int i=x; i<n; i++) {
				arr[i][m-1] = q.poll();
			}
			for(int i=m-2; i>=x; i--) {
				arr[n-1][i] = q.poll();
			}
			for(int i=n-2; i>=x; i--) {
				arr[i][x] = q.poll();
			}
			for(int i=x+1; i<m-1; i++) {
				arr[x][i] = q.poll();
			}
		}

		cal3(x+1, n-1, m-1);	
	}

	private static void cal2(int[][] arr, int x, int N, int M) {
		if(x == M/2) {
			return;
		}
		for(int i=0; i<N; i++) {
			q.add(arr[i][x]);
		}
		for(int i=0; i<N; i++) {
			q.add(arr[i][M-1-x]);
		}
		for(int i=0; i<N; i++) {
			arr[i][M-1-x] = q.poll();
		}
		for(int i=0; i<N; i++) {
			arr[i][x] = q.poll();
		}

		cal2(arr, x+1, N, M);
	}

	private static void cal1(int[][] arr, int x, int N, int M) {
		if(x == N/2) {
			return;
		}
		for(int i=0; i<M; i++) {
			q.add(arr[x][i]);
		}
		for(int i=0; i<M; i++) {
			q.add(arr[N-1-x][i]);
		}
		for(int i=0; i<M; i++) {
			arr[N-1-x][i] = q.poll();
		}
		for(int i=0; i<M; i++) {
			arr[x][i] = q.poll();
		}
		cal1(arr, x+1, N, M);
	}
}
