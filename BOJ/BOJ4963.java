package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ4963 {
	static int[] dc = new int[] {-1,-1,0,1,1,1,0,-1};
	static int[] dr = new int[] {0,1,1,1,0,-1,-1,-1};
	static int[][] map;
	static int w,h,count;
	static boolean[][] visit;
	static Queue<pair> q;
	static class pair{
		int x;
		int y;
		
		public pair() {
			
		}
		public pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			count = 0;
			map = new int[h][w];
			visit = new boolean[h][w];
			q = new LinkedList<pair>();
			if(w == 0 && h == 0) {
				break;
			}
			for(int i =0; i<h; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<w; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i =0; i<h; i++) {
				for(int j=0; j<w; j++) {
					if(map[i][j] == 1 && visit[i][j] == false) {
						q.add(new pair(i, j));
						visit[i][j] = true;
						solve();
						count++;
					}
					
				}
			}
			bw.write(count + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve() {
		while(!q.isEmpty()) {
			int c = q.peek().x;
			int r = q.peek().y;
			for(int i=0; i<8; i++) {
				int nc = c + dc[i];
				int nr = r + dr[i];
				if(nc >=0 && nc < h && nr >=0 && nr < w && visit[nc][nr] == false && map[nc][nr] == 1) {
					q.add(new pair(nc, nr));
					visit[nc][nr]=true;
				}
			}
			q.poll();
		}
	}

}
