package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ15686 {
	static ArrayList<pair> p;
	static int N, M, minn, min_dis;
	static int[][] city;
	static boolean[][] visit;
	
	static class pair{
		int x;
		int y;
		
		public pair() {}
		public pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		city = new int [N][N];
		visit = new boolean[N][N];
		min_dis = Integer.MAX_VALUE;
		p = new ArrayList<pair>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				city[i][j]= Integer.parseInt(st.nextToken());
			}
		}
		
		solve(0,0);
		bw.write(min_dis + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int idx, int cnt) {
		if (cnt == M) {
			min_dis = Math.min(min_dis, cal());
			return;
		}
		
		for (int i = idx; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (city[i][j] == 2 && visit[i][j] == false) {
					visit[i][j] = true;
					p.add(new pair(i,j));
					solve(i, cnt + 1);
					visit[i][j] = false;
					p.remove(p.size()-1);
				}
			}
		}
	}
	public static int cal() {
		int dis = 0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (city[i][j] == 1) {
					int k = 0;
					minn = Integer.MAX_VALUE;
					while (k < M) {
						dis = Math.abs(i - p.get(k).x) + Math.abs(j - p.get(k).y);
						minn = Math.min(minn, dis);
						k++;
					}
					sum = sum + minn;
				}
			}
		}
		
		return sum;
	}

}
