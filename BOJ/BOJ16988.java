package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ16988 {
	static int N, M, tcnt, Max = 0;
	static int[][] map;
	static int[] dx = {0,0,1,-1};
	static int[] dy = {1,-1,0,0};
	static boolean meet_zero;
	static boolean[][] check;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solves(new boolean[N][M]);
		bw.write(String.valueOf(Max));
		br.close();
		bw.close();
	}
	public static void solves(boolean[][] visit_first) {
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 0) {
					visit_first[i][j] = true;
					map[i][j] = 1;
					twoPoint(visit_first);
					map[i][j] = 0;
				}
			}
		}
	}
	private static void twoPoint(boolean[][] visit_first) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 0&&visit_first[i][j] == false) {
					map[i][j] = 1;
					int cnt=0;
					tcnt = 0;
					check = new boolean[N][M];
					meet_zero = false;
					for(int k=0;k<N;k++) {
						for(int l=0;l<M;l++) {
							if(map[k][l] == 2 && check[k][l] == false) {
								check[k][l] = true;
								tcnt++;
								dfs(l,k);
								if(meet_zero == false) {
										cnt+=tcnt;
										tcnt = 0;
								}else {
									meet_zero = false;
									tcnt = 0;
								}
							}
						}
					}
					if(Max < cnt)
						Max = cnt;
					map[i][j] = 0;
				}
			}
		}
	}

	public static void dfs(int x, int y) {
		
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||ny<0||nx>=M||ny>=N||map[ny][nx]==1||check[ny][nx] == true)continue;
			if(map[ny][nx] == 0) {
				meet_zero = true;
				continue;
			}
			tcnt++;
			check[ny][nx] = true;
			dfs(nx,ny);
		}
	}
}
