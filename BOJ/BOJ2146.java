package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ2146 {
	static int N, answer, num = 2;
	static int[][] map;
	static int[] dc = new int[] {-1,0,1,0};
	static int[] dr = new int[] {0,1,0,-1};
	static boolean[][] visit;
	static Queue<pair> q;
	static class pair{
		int x;
		int y;
		int z;
		
		public pair() {
			
		}
		
		public pair(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		visit = new boolean[N][N];
		answer = Integer.MAX_VALUE;
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<N; j++) {
				if(map[i][j] == 1 && visit[i][j] == false) {
					visit[i][j] = true;
					label(i, j);
					num++;
				}
			}
		}
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<N; j++) {
				if(map[i][j] > 1 ) {
					int dis = solve(i,j,map[i][j]);
					if(dis != -1) {
						answer = Math.min(answer, dis);
					}
				}
			}
		}
		
		bw.write(answer + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void label(int c, int r) {
		map[c][r] = num;
		for(int i =0; i<4; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			if(nc >=0 && nc < N && nr >=0 && nr < N && visit[nc][nr] == false && map[nc][nr] == 1) {
				label(nc, nr);
			}
		}
	}
	
	public static int solve(int x, int y, int n) {
		q = new LinkedList<pair>();
		visit = new boolean[N][N];
		q.add(new pair(x,y, 0));
		visit[x][y] = true;
		while(!q.isEmpty()) {
			int c = q.peek().x;
			int r = q.peek().y;
			int count = q.peek().z;
			q.poll();
			for(int j =0; j<4; j++) {
				int nc = c + dc[j];
				int nr = r + dr[j];
				if(nc >=0 && nc < N && nr >=0 && nr < N) {
					if(map[nc][nr] != 0 && map[nc][nr] != n) {
						return count;
					}
					else if(map[nc][nr] == 0 && visit[nc][nr] == false) {
						visit[nc][nr] = true;
						q.add(new pair(nc, nr, count +1));
					}
				}
			}
		}
		return -1;
	}
}
