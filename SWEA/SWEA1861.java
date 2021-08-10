package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA1861{
	static int[][] map;
	//상우하좌
	static int[] dc = {-1,1,0,0};
	static int[] dr = {0,0,-1,1};
	static int count, N;
	static boolean[][] visit; //이미 탐색했던 방인지 표시하기 위한 배열

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			st = new StringTokenizer(br.readLine());
			int answer = 1;					//이동횟수 중 가장 큰 값을 저장하기 위한 변수(현재의 방도 이동한 방의 갯수에 포함되므로 1로 초기화)
			int minroom =Integer.MAX_VALUE; //이동횟수에 따라 가장 작은 방의 값을 저장하기 위한 변수
            N = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            visit = new boolean[N][N];
            for(int i=0; i<N; i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j=0; j<N; j++) {
            		map[i][j] = Integer.parseInt(st.nextToken());
            		visit[i][j] = false;
            	}
            }
            for(int i=0; i<N; i++) {
            	for(int j=0; j<N; j++) {
            		//이미 방문했던 방이라면 이번 방 탐색 생략
            		if(visit[i][j]) {
            			break;
            		}
            		count = 1; //현재의 방도 이동한 방의 갯수에 포함되므로 1로 초기화
            		solve(i,j);
            		//이번 이동횟수가 현재까지 저장된 이동횟수의 max 값과 같다면
            		if(count == answer) {
            			//지금까지 저장된 가장 작은 방의 값과 이번 방의 값을 비교해서 작은 방의 값 저장
            			minroom = Math.min(minroom, map[i][j]);
            		}
            		//이번 이동횟수가 현재까지 저장된 이동횟수의 max 값보다 크다면
            		else if(count > answer) {
            			answer = count;        //이번 이동 횟수를 max값에 저장
            			minroom = map[i][j];   //가장 작은 방의 값을 현재의 방의 값으로 저장
            		}
            	}
            }
            bw.write("#" + test_case +" " + minroom + " " + answer + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int c, int r) {
		//상,우,하,좌 순서로 사방 탐색
		for(int i=0; i<4; i++) {
			int nc = c + dc[i];  //다음 행 값
			int nr = r + dr[i];  //다음 열 값
			// 다음 행과 열의 인덱스가 맵의 인덱스를 벗어나지 않고 현재의 방의 값보다 1크다면
			if(nc >= 0 && nc < N && nr >= 0 && nr < N &&  map[nc][nr] == map[c][r]+1) {
				count++;              //이동 횟수 증가
				visit[c][r] = true;   //현재 방의 위치를 방문했다고 표시
				solve(nc,nr);         //다음 방으로 가서 사방 탐색 하기위해 재귀 호출
			}
		}
	}
}