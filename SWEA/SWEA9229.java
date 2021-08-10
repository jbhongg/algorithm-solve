package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA9229 {
	static int M,answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			answer = Integer.MIN_VALUE;
			st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[N];
            for(int i = 0; i<N; i++) {
            	arr[i] = Integer.parseInt(st.nextToken());
            }
            
            solve(arr, new int[2], 0,0);
            
            bw.write("#" + test_case + " " + answer + '\n');
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int[] arr, int[] sel, int idx, int k) {
		if(k == sel.length) {
			if(sel[0] + sel[1] <= M) {
				answer = Math.max(answer, sel[0] + sel[1]);
			}
			else {
				answer = Math.max(answer, -1);
			}
			return;
		}
		
		for(int i=idx; i<arr.length; i++) {
			sel[k] = arr[i];
			solve(arr,sel,i+1,k+1);
		}
	}

}
