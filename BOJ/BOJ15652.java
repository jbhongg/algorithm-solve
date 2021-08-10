package com.ssafy.day01;

import java.util.Scanner;

public class BOJ15652 {
	static int[] sel;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		sel = new int[M];
		
		solve(N,M,0,0);
		System.out.println(sb);
	}
	
	private static void solve(int N, int M, int k, int idx) {
		if(idx == M) {
			for (int i = 0; i < M; i++) {
				sb.append(sel[i] + " ");
			}
			sb.append('\n');
			return;
		}
		for (int i = k; i < N; i++) {
			sel[idx] = i+1;
			solve(N,M,i,idx+1);
		}
	}
}
