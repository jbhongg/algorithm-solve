package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA3234 {
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T= Integer.parseInt(st.nextToken());
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			answer = 0;
			int[] num = new int[N];
			
			for(int i=0; i<N; i++) {
				num[i] = Integer.parseInt(st.nextToken());
			}
			
			solve(0, num, new boolean[N],0,0);
			bw.write("#" + test_case + " " + answer + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int k, int[] arr, boolean[] sel, int sum_L, int sum_R) {
		if(sum_L < sum_R) {
			return;
		}
		if(k == arr.length) {
			answer++;
			return;
		}
		for(int i=0; i<arr.length; i++) {
			if(!sel[i]) {
				sel[i] = true;
				solve(k+1, arr, sel, sum_L + arr[i], sum_R);
				solve(k+1, arr, sel, sum_L, sum_R + arr[i]);
				sel[i] = false;
			}
		}
	}

}
