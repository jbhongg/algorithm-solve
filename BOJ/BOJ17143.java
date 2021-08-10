package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ17143 {
	static int R, C, M, answer;
	static ArrayList<info> arr = new ArrayList<info>();;
	static int[][] map;
	static int[] dc = {-1,1,0,0};
	static int[] dr = {0,0,1,-1};
	
	static class info {
		int r, c, s, d, z;
		
		public info() {
			
		}
		
		public info(int r, int c, int s, int d, int z) {
            this.r = r;
            this.c = c;
            this.s = s;
            this.d = d;
            this.z = z;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[R+1][C+1];
		
		for(int i=1; i<M+1; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			arr.add(new info(x,y,a,b,c));
			map[x][y] = i; //맵에 해당 상어 index 번호 넣기
		}
		int idx = 0;
		//마지막 열까지 진행하면 종료
		while(idx != C) {
			idx++;
			kill(idx); //상어 잡기
			move(); //상어 이동
			check(); //칸에 2개이상의 상어 확인
			map = new int[R+1][C+1]; //맵 초기화
			//맵에 상어들의 위치에 해당 상어의 인덱스를 넣어줌
			for(int i=0; i<arr.size(); i++) {
				map[arr.get(i).r][arr.get(i).c] = i+1;
			}
		}
		
		bw.write(answer + "\n");
		br.close();
		bw.flush();
		bw.close();
	}
	public static void kill(int idx) {
		//열 아래로 탐색
		for(int i=1; i<R+1; i++) {
			//맵에 상어가 있으면
			if(map[i][idx] != 0) {
				int n = map[i][idx] -1; //해당 맵의 값 - 1이 상어의 인덱스 번호
				answer = answer + arr.get(n).z; //해당 상어의 크기 더해줌
				arr.remove(n); //해당 상어 삭제
				break;
			}
		}
	}
	public static void move() {
		for(int i=0; i<arr.size(); i++) {
			int count = 0;
			int nc = arr.get(i).r; 
			int nr = arr.get(i).c;
			//속도만큼 이동했으면 종료
			while(count != arr.get(i).s) {
				//이동 방향이 위쪽이면
				if(arr.get(i).d == 1) {
					//맵 끝에 도착했으면 방향을 반대로 바꿈
					if(nc == 1) {
						arr.get(i).d = 2;
					}
				}
				//이동 방향이 아래쪽이면
				else if(arr.get(i).d == 2) {
					//맵 끝에 도착했으면 방향을 반대로 바꿈
					if(nc == R) {
						arr.get(i).d = 1;
					}
				}
				//이동 방향이 오른쪽이면
				else if(arr.get(i).d == 3) {
					//맵 끝에 도착했으면 방향을 반대로 바꿈
					if(nr == C) {
						arr.get(i).d = 4;
					}
				}
				//이동 방향이 왼쪽이면
				else if(arr.get(i).d == 4) {
					//맵 끝에 도착했으면 방향을 반대로 바꿈
					if(nr == 1) {
						arr.get(i).d = 3;
					}
				}
				//이동 방향으로 한칸 이동
				nc = nc + dc[arr.get(i).d-1];
				nr = nr + dr[arr.get(i).d-1];
				count++; //이동 횟수 증가
			}
			//해당 상어의 위치를 이동한 위치로 바꿔줌
			arr.get(i).r = nc;
			arr.get(i).c = nr;
		}
	}
	public static void check() {
		//행, 열, 크기 순으로 정렬
		arr.sort(new Comparator<info>() {

			@Override
			public int compare(info o1, info o2) {
				if(o1.r == o2.r) {
					if(o1.c == o2.c) {
						return o1.z - o2.z;
					}
					return o1.c - o2.c;
				}
				return o1.r - o2.r;
			}
		});
		for(int i=0; i< arr.size()-1; i++) {
			//현재 상어와 다음 상어의 행이 같으면
			if(arr.get(i).r == arr.get(i+1).r) {
				//현재 상어와 다음 상어의 열이 같으면
				if(arr.get(i).c == arr.get(i+1).c) {
					arr.remove(i); //현재 상어 삭제
					i = i-1; //인덱스 하나 줄여서 다시 탐색
				}
			}
		}
	}

}
