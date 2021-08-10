package com.ssafy.day01;

import java.util.Scanner;

public class BOJ15649 {
	static int[] sel;
	static boolean[] visit;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		visit = new boolean[N];
		sel = new int[M];
		
		solve(N,M,0);
	}
	
	private static void solve(int N, int M, int idx) {
		if(idx == M) {
			for(int i : sel) {
				System.out.print(i + " ");
			}
			System.out.println();
			return;
		}
		for (int i = 0; i < N; i++) {
			if(!visit[i]) {
				visit[i] = true;
				sel[idx] = i+1;
				solve(N,M,idx+1);
				visit[i] = false;
			}
		}
	}

}
