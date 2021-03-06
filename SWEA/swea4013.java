package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class swea4013 {
	static ArrayList<Integer>[] gear;
	static pair[] rotation;
	static int dir_0, dir_1, dir_2, dir_3;
	
	static class pair{
		int num;
		int dir;
		
		public pair() {
			
		}

		public pair(int num, int dir) {
			super();
			this.num = num;
			this.dir = dir;
		}
	}

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int test_case = 1; test_case <= T; test_case++) {
        	st = new StringTokenizer(br.readLine());
        	int sum = 0;
        	int K = Integer.parseInt(st.nextToken());
        	rotation = new pair[100];
        	gear = new ArrayList[4];
        	for (int i = 0; i < 4; i++) {
        		st = new StringTokenizer(br.readLine());
        		gear[i] = new ArrayList<Integer>();
        		for (int j = 0; j < 8; j++) {
        			int temp = Integer.parseInt(st.nextToken());
        			gear[i].add(temp);
        		}
        	}
        	for (int i = 0; i < K; i++) {
        		st = new StringTokenizer(br.readLine());
        		rotation[i] = new pair();
        		rotation[i].num =  Integer.parseInt(st.nextToken());
        		rotation[i].dir = Integer.parseInt(st.nextToken());
        		solve(rotation[i].num, rotation[i].dir);
        	}
        	if (gear[0].get(0) == 1) {
        		sum = sum + 1;
        	}
        	if (gear[1].get(0) == 1) {
        		sum = sum + 2;
        	}
        	if (gear[2].get(0) == 1) {
        		sum = sum + 4;
        	}
        	if (gear[3].get(0) == 1) {
        		sum = sum + 8;
        	}
            
            bw.write("#" + test_case + " " + sum + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
	
	public static void solve(int num, int dir) {
		int n = num - 1;

		switch (n) {
		//1??? ??????????????????
		case 0:
		{
			dir_0 = dir; //1??? ??????????????? ??????????????? ???????????? ????????????
			//2??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[0].get(2) == gear[1].get(6)) {
				dir_1 = 0; //2??? ???????????? ?????? x
				dir_2 = 0; //3??? ???????????? ?????? x
				dir_3 = 0; //4??? ???????????? ?????? x
				break;
			}
			//2??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//1??? ??????????????? ??????????????? ?????????????????????
				if (dir_0 == 1) {
					dir_1 = -1; //2??? ??????????????? ??????????????? ????????? ??????
				}
				//1??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_1 = 1; //2??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//2??? ??????????????? 3??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[1].get(2) == gear[2].get(6)) {
				dir_2 = 0; //3??? ???????????? ?????? x
				dir_3 = 0; //4??? ???????????? ?????? x
				break;
			}
			//2??? ??????????????? 3??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//2??? ??????????????? ??????????????? ?????????????????????
				if (dir_1 == 1) {
					dir_2 = -1; //3??? ??????????????? ??????????????? ????????? ??????
				}
				//2??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_2 = 1; //3??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//3??? ??????????????? 4??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[2].get(2) == gear[3].get(6)) {
				dir_3 = 0; //4??? ???????????? ?????? x
			}
			//3??? ??????????????? 4??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//3??? ??????????????? ??????????????? ?????????????????????
				if (dir_2 == 1) {
					dir_3 = -1; //4??? ??????????????? ??????????????? ????????? ??????
				}
				//3??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_3 = 1; //4??? ??????????????? ??????????????? ?????? ??????
				}
			}
			break;
		}
		//2??? ??????????????????
		case 1:
		{
			dir_1 = dir; //2??? ??????????????? ??????????????? ???????????? ????????????
			//1??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[1].get(6) == gear[0].get(2)) {
				dir_0 = 0; //1??? ???????????? ?????? x
			}
			//1??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//2??? ??????????????? ??????????????? ?????????????????????
				if (dir_1 == 1) {
					dir_0 = -1; //1??? ??????????????? ??????????????? ????????? ??????
				}
				//2??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_0 = 1; //1??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//3??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[1].get(2) == gear[2].get(6)) {
				dir_2 = 0; //3??? ???????????? ?????? x
				dir_3 = 0; //4??? ???????????? ?????? x
				break;
			}
			//3??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//2??? ??????????????? ??????????????? ?????????????????????
				if (dir_1 == 1) {
					dir_2 = -1; //3??? ??????????????? ??????????????? ????????? ??????
				}
				//2??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_2 = 1; //3??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//3??? ??????????????? 4??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[2].get(2) == gear[3].get(6)) {
				dir_3 = 0; //4??? ???????????? ?????? x
			}
			//3??? ??????????????? 4??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//3??? ??????????????? ??????????????? ?????????????????????
				if (dir_2 == 1) {
					dir_3 = -1; //4??? ??????????????? ??????????????? ????????? ??????
				}
				//3??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_3 = 1; //4??? ??????????????? ??????????????? ?????? ??????
				}
			}
			break;
		}
		//3??? ??????????????????
		case 2:
		{
			dir_2 = dir; //3??? ??????????????? ??????????????? ???????????? ????????????
			//4??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[2].get(2) == gear[3].get(6)) {
				dir_3 = 0; //4??? ???????????? ?????? x
			}
			//4??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//3??? ??????????????? ??????????????? ?????????????????????
				if (dir_2 == 1) {
					dir_3 = -1; //4??? ??????????????? ??????????????? ????????? ??????
				}
				//3??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_3 = 1; //4??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//2??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[2].get(6) == gear[1].get(2)) {
				dir_1 = 0; //2??? ???????????? ?????? x
				dir_0 = 0; //1??? ???????????? ?????? x
				break;
			}
			//2??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//3??? ??????????????? ??????????????? ?????????????????????
				if (dir_2 == 1) {
					dir_1 = -1; //2??? ??????????????? ??????????????? ????????? ??????
				}
				//3??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_1 = 1; //2??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//1??? ??????????????? 2??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[1].get(6) == gear[0].get(2)) {
				dir_0 = 0; //1??? ???????????? ?????? x
			}
			//1??? ??????????????? 2??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//2??? ??????????????? ??????????????? ?????????????????????
				if (dir_1 == 1) {
					dir_0 = -1; //1??? ??????????????? ??????????????? ????????? ??????
				}
				//2??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_0 = 1; //1??? ??????????????? ??????????????? ?????? ??????
				}
			}
			break;
		}
		//4??? ??????????????????
		case 3:
		{
			dir_3 = dir; //4??? ??????????????? ??????????????? ???????????? ????????????
			//3??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[3].get(6) == gear[2].get(2)) {
				dir_2 = 0; //3??? ???????????? ?????? x
				dir_1 = 0; //2??? ???????????? ?????? x
				dir_0 = 0; //1??? ???????????? ?????? x
				break;
			}
			//3??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//4??? ??????????????? ??????????????? ?????????????????????
				if (dir_3 == 1) {
					dir_2 = -1; //3??? ??????????????? ??????????????? ????????? ??????
				}
				//4??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_2 = 1; //3??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//2??? ??????????????? 3??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[2].get(6) == gear[1].get(2)) {
				dir_1 = 0; //2??? ???????????? ?????? x
				dir_0 = 0; //1??? ???????????? ?????? x
				break;
			}
			//2??? ??????????????? 3??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//3??? ??????????????? ??????????????? ?????????????????????
				if (dir_2 == 1) {
					dir_1 = -1; //2??? ??????????????? ??????????????? ????????? ??????
				}
				//3??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_1 = 1; //2??? ??????????????? ??????????????? ?????? ??????
				}
			}
			//1??? ??????????????? 2??? ??????????????? ???????????? ?????? ?????? ?????????
			if (gear[1].get(6) == gear[0].get(2)) {
				dir_0 = 0; //1??? ???????????? ?????? x
			}
			//1??? ??????????????? 2??? ??????????????? ???????????? ?????? ?????? ????????????
			else {
				//2??? ??????????????? ??????????????? ?????????????????????
				if (dir_1 == 1) {
					dir_0 = -1; //1??? ??????????????? ??????????????? ????????? ??????
				}
				//2??? ??????????????? ??????????????? ????????????????????????
				else {
					dir_0 = 1; //1??? ??????????????? ??????????????? ?????? ??????
				}
			}
			break;
		}
		}
		move();
	}
	public static void move() {
		//1??? ??????????????? ??????????????? ?????????????????????
		if (dir_0 == 1) {
			clock(0);
		}
		//1??? ??????????????? ??????????????? ????????????????????????
		else if (dir_0 == -1) {
			op_clock(0);
		}

		//2??? ??????????????? ??????????????? ?????????????????????
		if (dir_1 == 1) {
			clock(1);
		}
		//2??? ??????????????? ??????????????? ????????????????????????
		else if (dir_1 == -1) {
			op_clock(1);
		}

		//3??? ??????????????? ??????????????? ?????????????????????
		if (dir_2 == 1) {
			clock(2);
		}
		//3??? ??????????????? ??????????????? ????????????????????????
		else if (dir_2 == -1) {
			op_clock(2);
		}

		//4??? ??????????????? ??????????????? ?????????????????????
		if (dir_3 == 1) {
			clock(3);
		}
		//4??? ??????????????? ??????????????? ????????????????????????
		else if (dir_3 == -1) {
			op_clock(3);
		}
	}
	
	public static void clock(int m) {
		int temp = gear[m].get(7);
		for (int i = 7; i > 0; i--) {
			gear[m].set(i, gear[m].get(i - 1)); 
		}
		gear[m].set(0, temp);
	}
	
	public static void op_clock(int n) {
		int temp = gear[n].get(0);
		for (int i = 0; i < 7; i++) {
			gear[n].set(i, gear[n].get(i + 1));
		}
		gear[n].set(7, temp);
	}

}
