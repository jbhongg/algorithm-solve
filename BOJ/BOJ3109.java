package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ3109 {
	static int R, C, count;
	static char[][] map;
	static int[] dc = new int[] {-1,0,1};
	static int[] dr = new int[] {1,1,1};
	static boolean flag;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		
		for(int i =0; i<R; i++) {
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			for(int j=0; j<s.length(); j++) {
				map[i][j] = s.charAt(j);
			}
		}
		
		for(int i = 0; i<R; i++) {
			if(map[i][0] == '.') {
				flag = false;
				solve(i,0);
			}
		}
		bw.write(count + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int c, int r) {
		if(flag) {
			return;
		}
		map[c][r] = 'X';
		if(r == C-1) {
			count++;
			flag = true;
			return;
		}
		for(int i=0; i<3; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			if(nc >=0 && nc < R && nr >=0 && nr < C && map[nc][nr] == '.') {
				solve(nc, nr);
			}
		}
					
	}
}
