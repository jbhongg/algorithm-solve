package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ1194 {
	static int N, M;
	static char map[][];
	static Queue<info> q = new LinkedList<info>();
	static boolean visit[][][];
	static int dc[] = {-1,0,1,0};
	static int dr[] = {0,1,0,-1};
	
	static class info {
		int c;
		int r;
		int cnt;
		int key;
		
		public info() {
			
		}
		
		public info(int c, int r, int cnt, int key) {
			this.c = c;
			this.r = r;
			this.cnt = cnt;
			this.key = key;
		}
		
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		visit = new boolean[128][N][M];
		map = new char[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			for (int j = 0; j < M; j++) {
				map[i][j] = s.charAt(j);
				if (map[i][j] == '0') {
					q.add(new info(i,j,0,0));
					visit[0][i][j] = true;
					map[i][j] = '.';
				}
			}
		}
		
		bw.write(solve() + "\n");
		br.close();
		bw.flush();
		bw.close();	
	}
	public static int solve() {
		while (!q.isEmpty())
		{
			int c = q.peek().c;
			int r = q.peek().r;
			int cnt = q.peek().cnt;
			int key = q.peek().key;
			q.poll();
			if (map[c][r] == '1') {
				return cnt;
			}
			for (int i = 0; i < 4; i++) {
				int nc = c + dc[i];
				int nr = r + dr[i];
				if (nc >= 0 && nc < N && nr >= 0 && nr < M && map[nc][nr] != '#' && !visit[key][nc][nr]) {
					if (map[nc][nr] == 'a') {
						int nkey = key | 1;
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'b') {
						int nkey = key | (1 << 1);
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'c') {
						int nkey = key | (1 << 2);
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'd') {
						int nkey = key | (1 << 3);
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'e') {
						int nkey = key | (1 << 4);
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'f') {
						int nkey = key | (1 << 5);
						q.add(new info(nc, nr, cnt+1, nkey));
						visit[nkey][nc][nr] = true;
					}
					else if (map[nc][nr] == 'A') {
						if ((key & 1) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else if (map[nc][nr] == 'B') {
						if ((key & (1 << 1)) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else if (map[nc][nr] == 'C') {
						if ((key & (1 << 2)) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else if (map[nc][nr] == 'D') {
						if ((key & (1 << 3)) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else if (map[nc][nr] == 'E') {
						if ((key & (1 << 4)) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else if (map[nc][nr] == 'F') {
						if ((key & (1 << 5)) != 0) {
							q.add(new info(nc, nr, cnt+1, key));
							visit[key][nc][nr] = true;
						}
					}
					else {
						q.add(new info(nc, nr, cnt+1, key));
						visit[key][nc][nr] = true;
					}
				}
			}
		}

		return -1;
	}

}
