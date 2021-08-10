package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ15683 {
	static int N, M, cnt, cctv, minn = 64;
	static int[][] office;
	static int[][] temp;
	static ArrayList<info> arr = new ArrayList<info>();
	
	static class info{
		int c;
		int r;
		int num;
		int dir;
		
		public info() {
			
		}

		public info(int c, int r, int num, int dir) {
			super();
			this.c = c;
			this.r = r;
			this.num = num;
			this.dir = dir;
		}
	}

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        office = new int[N][M];
        temp = new int[N][M];
        
    	for (int i = 0; i < N; i++) {
    		st = new StringTokenizer(br.readLine());
    		for (int j = 0; j < M; j++) {
    			office[i][j] = Integer.parseInt(st.nextToken());
    			if (office[i][j] != 0 && office[i][j] != 6) {
    				arr.add(new info(i,j,office[i][j], -1));
    				cctv++;
    			}
    		}
    	}
    	
    	solve(0);
    	bw.write(minn + "\n");
    	br.close();
    	bw.flush();
    	bw.close();
	}
	public static void solve(int count) {
		if (count == cctv) {
			check();
			minn = Math.min(minn, cal());
			return;
		}

		arr.get(count).dir= 0;
		solve(count + 1);

		arr.get(count).dir = 1;
		solve(count + 1);

		arr.get(count).dir = 2;
		solve(count + 1);

		arr.get(count).dir = 3;
		solve(count + 1);

	}
	
	public static void check(){
		reset();
		for (int i = 0; i < cctv; i++) {
			if (arr.get(i).num == 1) {
				if (arr.get(i).dir == 0) {
					east(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 1) {
					west(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 2) {
					south(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 3) {
					north(arr.get(i).c, arr.get(i).r);
				}

			}
			else if (arr.get(i).num == 2) {
				if (arr.get(i).dir == 0 || arr.get(i).dir == 1) {
					east(arr.get(i).c, arr.get(i).r);
					west(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 2 || arr.get(i).dir == 3) {
					south(arr.get(i).c, arr.get(i).r);
					north(arr.get(i).c, arr.get(i).r);
				}

			}
			else if (arr.get(i).num == 3) {
				if (arr.get(i).dir == 0) {
					east(arr.get(i).c, arr.get(i).r);
					north(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 1) {
					west(arr.get(i).c, arr.get(i).r);
					south(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 2) {
					south(arr.get(i).c, arr.get(i).r);
					east(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 3) {
					north(arr.get(i).c, arr.get(i).r);
					west(arr.get(i).c, arr.get(i).r);
				}

			}
			else if (arr.get(i).num == 4) {
				if (arr.get(i).dir == 0) {
					east(arr.get(i).c, arr.get(i).r);
					west(arr.get(i).c, arr.get(i).r);
					north(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 1) {
					west(arr.get(i).c, arr.get(i).r);
					east(arr.get(i).c, arr.get(i).r);
					south(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 2) {
					south(arr.get(i).c, arr.get(i).r);
					north(arr.get(i).c, arr.get(i).r);
					west(arr.get(i).c, arr.get(i).r);
				}
				else if (arr.get(i).dir == 3) {
					south(arr.get(i).c, arr.get(i).r);
					north(arr.get(i).c, arr.get(i).r);
					east(arr.get(i).c, arr.get(i).r);
				}

			}
			else if (arr.get(i).num == 5) {
				east(arr.get(i).c, arr.get(i).r);
				west(arr.get(i).c, arr.get(i).r);
				south(arr.get(i).c, arr.get(i).r);
				north(arr.get(i).c, arr.get(i).r);
			}
		}
	}

	public static int cal() {
		int result = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) {
					result++;
				}
			}
		}

		return result;
	}
	
	public static void reset() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = office[i][j];
			}
		}
	}
	
	public static void east(int x, int y) {
		int b = y;
		while (y < M - 1) {
			y++;
			if (temp[x][y] == 6) {
				break;
			}
			else if (temp[x][y] == 0) {
				temp[x][y] = -1;
			}
		}
		y = b;
	}
	
	public static void west(int x, int y) {
		int b = y;
		while (y > 0) {
			y--;
			if (temp[x][y] == 6) {
				break;
			}
			else if (temp[x][y] == 0) {
				temp[x][y] = -1;
			}
		}
		y = b;
	}
	
	public static void south(int x, int y) {
		int a = x;
		while (x < N - 1) {
			x++;
			if (temp[x][y] == 6) {
				break;
			}
			else if (temp[x][y] == 0) {
				temp[x][y] = -1;
			}
		}
		x = a;
	}
	
	public static void north(int x, int y) {
		int a = x;
		while (x > 0) {
			x--;
			if (temp[x][y] == 6) {
				break;
			}
			else if (temp[x][y] == 0) {
				temp[x][y] = -1;
			}
		}
		x = a;
	}
}
