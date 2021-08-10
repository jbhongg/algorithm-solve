package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ17406 {
	static int R, min, answer, N, M;
	static int[][] arr;
	static int[][] temp;
	static int[][] info;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		answer = Integer.MAX_VALUE;
		R = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		temp = new int[N][M];
		info = new int[R][3];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				temp[i][j] = arr[i][j];
			}
		}
		
		for(int i=0; i<R; i++) {
			st = new StringTokenizer(br.readLine());
			info[i][0] = Integer.parseInt(st.nextToken());
			info[i][1] = Integer.parseInt(st.nextToken());
			info[i][2] = Integer.parseInt(st.nextToken());
		}
		
		permutation(new int[R] , 0, new boolean[R]);
		
		bw.write(answer + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
 	public static void permutation(int[] sel, int k, boolean[] visit) {
 		if(k == R) {
 			for(int i =0; i<R; i++) {
 				if (((info[sel[i]][0] + info[sel[i]][2]) - (info[sel[i]][0] - info[sel[i]][2] - 1)) >= ((info[sel[i]][1] + info[sel[i]][2]) - (info[sel[i]][1] - info[sel[i]][2] - 1))) {
 					min = ((info[sel[i]][1] + info[sel[i]][2]) - (info[sel[i]][1] - info[sel[i]][2] - 1));
 				}
 				else {
 					min = ((info[sel[i]][0] + info[sel[i]][2]) - (info[sel[i]][0] - info[sel[i]][2] - 1));
 				}
 				rotate(info[sel[i]][0] - info[sel[i]][2] - 1, info[sel[i]][1] - info[sel[i]][2] - 1, info[sel[i]][0] + info[sel[i]][2], info[sel[i]][1] + info[sel[i]][2],0);
 			}
 			for(int[] a : temp) {
 				int sum = 0;
 				for(int b : a) {
 					sum = sum + b;
 				}
 				answer = Math.min(answer, sum);
 			}
 			init();
 			return;
 		}
		for (int i = 0; i < R; i++) {
			if(visit[i]==false) {
				visit[i]=true;
				sel[k]= i;
				permutation(sel, k+1, visit);
				visit[i]=false;
			}
		}
 	}
	public static void rotate(int x, int y, int n, int m, int count) {
		if (count == (min / 2)) {
			return;
		}
		
		Queue<Integer> q = new LinkedList<Integer>(); 
		
		for (int j = m-1; j >= y; j--) {
			q.add(temp[x][j]);
		}
		for (int i = x + 1; i < n; i++) {
			q.add(temp[i][y]);
		}
		for (int j = y + 1; j < m; j++) {
			q.add(temp[n - 1][j]);
		}
		for (int i = n - 2; i >= x + 1; i--) {
			q.add(temp[i][m-1]);
		}
		
		q.add(q.poll());
		
		for (int j = m-1; j >= y; j--) {
			temp[x][j] = q.poll();
		}
		for (int i = x + 1; i < n; i++) {
			temp[i][y] = q.poll();
		}
		for (int j = y+1; j < m; j++) {
			temp[n - 1][j] = q.poll();
		}
		for (int i = n - 2; i >= x + 1; i--) {
			temp[i][m-1] = q.poll();
		}
		
		rotate(x + 1, y + 1, n - 1, m - 1, count+1);
	}
	public static void init() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}
	}

}
