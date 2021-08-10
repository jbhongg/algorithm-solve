package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2636 {
	static int[][] map;
	static int[] dc = {-1,0,1,0};
	static int[] dr = {0,1,0,-1};
	static int n, m, cnt, time, total;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				//초기 치즈 갯수 세서 저장
				if (map[i][j] == 1) {
					total++;
				}
			}
		}
		label(0,0); //초기 라벨링(공기)
		while (true) {
			cnt = 0; //녹은 치즈를 세기위한 변수 초기화
			//녹을 치즈 탐색
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] == 1) {
						check(i,j); //현재 치즈가 녹을 치즈인지를 판단하기 위한 함수
					}
				}
			}
			//녹을 치즈가 모두 녹은 후 치즈를 녹일 수 있는 공기를 탐색
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					//공기를 만나면
					if (map[i][j] == 0) {
						//사방 탐색
						for (int k = 0; k < 4; k++) {
							int nc = i + dc[k];
							int nr = j + dr[k];
							//이동할 위치가 맵안에 있고 치즈를 녹일 수 있는 공기라면
							if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == -1) {
								label(i,j); //현재 위치 라벨링
							}
						}
					}
				}
			}
			time++; //시간 증가
			//이전 치즈 갯수에서 녹은 치즈갯수를 뺀값이 0이라면(치즈가 모두 녹았다는 것을 의미) 종료
			if ((total - cnt) == 0) {
				break;
			}
			total = total - cnt; //아니면 현재 치즈 수 저장
		}
		
		bw.write(time + "\n" + cnt + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void label(int c, int r) {
		//현재 위치를 -1로 표시(치즈를 녹일 수 있는 공기라는 것을 표시)
		map[c][r] = -1;
		//사방 탐색
		for (int i = 0; i < 4; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			//이동할 위치가 맵안에 있고 공기라면 재귀
			if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == 0) {
				label(nc, nr);
			}
		}
	}
	public static void check(int c, int r) {
		//사방 탐색
		for (int i = 0; i < 4; i++) {
			int nc = c + dc[i];
			int nr = r + dr[i];
			//이동할 위치가 맵안에 있고 공기라면
			if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == -1) {
				cnt++; //녹는 치즈이므로 갯수 증가
				map[c][r] = 0; //현재 위치를 0으로 표시(치즈가 녹음) 후 종료
				return;
			}
		}
	}

}
