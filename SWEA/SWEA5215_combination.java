package com.ssafy.day01;

import java.util.Scanner;

public class SWEA5215_combination {
	static pair[] p;
	static int N, L, sumL, score; 
	static int max;
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
		for(int i = x; i<N; i++) {
			if(sumL + p[i].second <= L) {
				sumL = sumL + p[i].second;
				score = score + p[i].first;
				max = Math.max(max, score);
				solve(i+1);
				score =  score - p[i].first;
				sumL = sumL - p[i].second;
			}
		}
	}

}
