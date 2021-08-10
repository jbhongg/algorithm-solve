package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ1520 {
	static int M, N;
	static int[][] map;
	static int[][] visit;
	static int[] dc = {-1,0,1,0};
	static int[] dr = {0,1,0,-1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[M][N];
		visit = new int[M][N];
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				visit[i][j] = -1;
			}
		}
		
		bw.write(solve(0,0) + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static int solve(int c, int r) {
		if(visit[c][r] != -1) {
			return visit[c][r];
		}
		if(c == M-1 && r == N-1) {
			return 1;
		}
		visit[c][r] = 0;
		for(int i = 0; i<4; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			if(nc>=0 && nc < M && nr>=0 && nr <N) {
				if(map[c][r] > map[nc][nr]) {
					visit[c][r] += solve(nc, nr);
				}
			}
		}
		return visit[c][r];
	}
}
