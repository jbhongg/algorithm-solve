package com.ssafy.day01;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ15654 {
	static int[] arr;
	static int[] sel;
	static boolean[] visit;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		arr = new int[N];
		visit = new boolean[N];
		sel = new int[M];
		
		for(int i =0; i<N; i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		solve(N,M,0);
		System.out.println(sb);
	}
	
	private static void solve(int N, int M, int idx) {
		if(idx == M) {
			for (int i = 0; i < M; i++) {
				sb.append(sel[i] + " ");
			}
			sb.append('\n');
			return;
		}
		for (int i = 0; i < N; i++) {
			if(!visit[i]) {
				visit[i] = true;
				sel[idx] = arr[i];
				solve(N,M,idx+1);
				visit[i] = false;
			}
		}
	}
}
