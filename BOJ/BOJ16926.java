package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ16926 {
	static Queue<Integer> q = new LinkedList<Integer>(); 
	static int R, min;
	static int[][] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		if (N >= M) {
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
		
		rotate(0,N,M);
		
		for(int[] a : arr) {
			for(int b : a) {
				bw.write(b + " ");
			}
			bw.write('\n');
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void rotate(int x, int n, int m) {
		if (x == (min / 2)) {
			return;
		}
		for (int j = x; j < m; j++) {
			q.add(arr[x][j]);
		}
		for (int i = x + 1; i < n; i++) {
			q.add(arr[i][m - 1]);
		}
		for (int j = m - 2; j >= x; j--) {
			q.add(arr[n - 1][j]);
		}
		for (int i = n - 2; i >= x + 1; i--) {
			q.add(arr[i][x]);
		}
		
		for (int i = 0; i < R; i++) {
			q.add(q.poll());
		}
		
		for (int j = x; j < m; j++) {
			arr[x][j] = q.poll();
		}
		for (int i = x + 1; i < n; i++) {
			arr[i][m - 1] = q.poll();
		}
		for (int j = m - 2; j >= x; j--) {
			arr[n - 1][j] = q.poll();
		}
		for (int i = n - 2; i >= x + 1; i--) {
			arr[i][x] = q.poll();
		}
		
		rotate(x + 1, n - 1, m - 1);
	}

}
