package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ18868 {
	static int[][] map;
	static int M,N,count;
	static boolean flag;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[M][N];
		for(int i =0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve(0);
		bw.write(count + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int k) {
		if(k == M) {
			return;
		}
	
		for(int i = k+1; i <M; i++) {
			flag = false;
			for(int j = 0; j<N-1; j++) {
				int cnt = j+1;
				while(cnt != N) {
					if(map[k][j] < map[k][cnt] && map[i][j] < map[i][cnt]) {
						cnt++;
						continue;
					}
					else if(map[k][j] == map[k][cnt] && map[i][j] == map[i][cnt]) {
						cnt++;
						continue;
					}
					else if(map[k][j] > map[k][cnt] && map[i][j] > map[i][cnt]) {
						cnt++;
						continue;
					}
					flag = true;
					break;
				}
				if(flag) {
					break;
				}

			}
			if(!flag) {
				count++;
			}
		}
		solve(k+1);
	}

}
