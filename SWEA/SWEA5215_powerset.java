package com.ssafy.day01;

import java.util.Scanner;

public class SWEA5215_powerset {
	static pair[] p;
	static int N, L;
	static int max;
	static boolean[] b;
	static class pair{
		int first;
		int second;
		
		public pair(){}
		public pair(int first, int second){
			this.first = first;
			this.second = second;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			L = sc.nextInt();
			max = Integer.MIN_VALUE;
			b = new boolean[N];
			p = new pair[N];
			for(int i = 0; i<N; i++) {
				p[i] = new pair();
				p[i].first = sc.nextInt();
				p[i].second = sc.nextInt();
			}
			solve(0);
			
			System.out.println("#" + test_case + " " + max);
		}
	}
	public static void solve(int x) {
		if(x == N) {
			int sumL = 0, score = 0;
			for(int i = 0; i<N; i++) {
				if(b[i]) {
					score = score + p[i].first;
					sumL = sumL + p[i].second;
				}
			}
			if(sumL <= L) {
				max = Math.max(max, score);
			}
			return;
		}
		b[x] = true;
		solve(x+1);
		b[x] = false;
		solve(x+1);
	}

}
