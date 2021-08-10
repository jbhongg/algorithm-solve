package com.ssafy.day01;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ15657 {
	static int[] arr;
	static int[] sel;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		arr = new int[N];
		sel = new int[M];
		
		for(int i =0; i<N; i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
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
			sel[idx] = arr[i];
			solve(N,M,i,idx+1);
		}
	}
}
