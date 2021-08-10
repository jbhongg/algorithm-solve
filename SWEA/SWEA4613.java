package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA4613 {
	static int N, M, answer,count;
	static char[][] map;
	static int[] num;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T= Integer.parseInt(st.nextToken());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			st = new StringTokenizer(br.readLine());
			answer = Integer.MAX_VALUE;
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			num = new int[3];
			map = new char[N][M];
			for(int i =0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				String s = st.nextToken();
				for(int j = 0; j<s.length(); j++) {
					map[N][M] = s.charAt(j);
				}
			}
			
			solve(0,N-1,num);
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int k, int idx, int[] num) {
		char color = '\0';
		
		if(idx < 0) {
			answer = Math.min(answer, count);
			return;
		}
		if(k==0) {
			color = 'R';
		}
		
		for(int i = 0; i<N-3; i++) {
			solve(k+1,i,num);
		}
	}
	public static void cal(int c, int r, char color) {
		for(int i=0; i<r; i++) {
			if(map[c][i] != color) {
				count++;
			}
		}
	}

}
