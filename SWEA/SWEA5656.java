package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA5656 {
	static int answer, N, W, H;
	static int[][] map;
	static int[][] temp;
	static int[] ball;
	static int dc[] = {-1,0,1,0};
	static int dr[] = {0,1,0,-1};
	static Queue<info> q = new LinkedList<info>();
	static boolean visit[][]; 
	
	static class info{
		int c;
		int r;
		int n;
		
		public info() {
			
		}
		
		public info(int c, int r, int n) {
			this.c = c;
			this.r = r;
			this.n = n;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; ++test_case)
		{
			st = new StringTokenizer(br.readLine());
			answer = Integer.MAX_VALUE;
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			map = new int[H][W];
			temp = new int[H][W];
			ball = new int[N];
			visit = new boolean[H][W];
			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < W; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					temp[i][j] = map[i][j];
				}
			}

			solve(0);
			bw.write("#" + test_case + " " + answer + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int k) {
		//0보다 작을 수는 없으므로 종료
		if (answer == 0) {
			return;
		}
		//다 뽑았으면
		if (k == N) {
			bomb();
			count();
			init();
			return;
		}
		
		//중복 조합
		for (int i = 0; i < W; i++) {
			ball[k] = i;
			solve(k + 1);
		}
	}
	public static void bomb() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < H; j++) {
				//구슬을 떨어트린 열에 첫 벽돌을 만나면
				if (temp[j][ball[i]] != 0) {
					//(행,열),벽돌 수 저장
					q.add(new info(j,ball[i],temp[j][ball[i]]));
					bfs();
					move();
					visit = new boolean[H][W];
					break;
				}
			}
		}
	}
	public static void count() {
		int count = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (temp[i][j] != 0) {
					count++;
				}
			}
		}
		answer = Math.min(answer, count); //가장 적게 남은 벽돌 수 저장
	}
	public static void init() {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				temp[i][j] = map[i][j];
			}
		}
	}
	public static void bfs() {
		while (!q.isEmpty()) {
			int c = q.peek().c;
			int r = q.peek().r;
			int n = q.peek().n;
			q.poll();
			//벽돌의 수가 0과 1이 아니면
			if (n != 0 && n != 1) {
				//벽돌에 적힌 수-1 만큼 반복
				for (int i = 1; i <= (n - 1); i++) {
					//사방 탐색
					for (int j = 0; j <4; j++) {
						//벽돌에 적힌 수-1 만큼 같이 벽돌이 부셔지므로 *i를 함
						int nc = c + (dc[j]*i);
						int nr = r + (dr[j]*i);
						//다음 위치의 배열이 맵안에 있고 값이 0이 아니고 방문하지 않은 배열이라면
						if (nc >= 0 && nc < H && nr >= 0 && nr < W && temp[nc][nr] != 0 && visit[nc][nr] == false) {
							//큐에 저장하고 방문 표시
							q.add(new info(nc, nr,temp[nc][nr]));
							visit[nc][nr] = true;
						}
					}
				}
				//현재 위치 배열의 값 0으로 바꿔주고 큐에서 제거
				temp[c][r] = 0;
			}
			//벽돌의 수가 1이면 그 자리만 0으로 바꿈
			else if (n == 1) {
				temp[c][r] = 0;
			}
		}
	}
	public static void move() {
		//아래서부터 열 탐색
		for (int j = 0; j < W; j++) {
			for (int i = H - 1; i > 0; i--) {
				//벽돌이 없다면
				if (temp[i][j] == 0) {
					int k = i - 1;
					//벽돌이 있을때까지 탐색
					while (temp[k][j] == 0) {
						k--;
						if (k < 0) {
							break;
						}
					}
					//벽돌이 있는 위치와 현재 위치의 값을 바꿔줌
					if (k >= 0) {
						temp[i][j] = temp[k][j];
						temp[k][j] = 0;
					}
					else {
						break;
					}
				}
			}
		}
	}
}
