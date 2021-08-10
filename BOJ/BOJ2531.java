package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2531 {

	static int N, d, k, c;
	static int[] dish;
	static boolean[] kind;
	static int answer = Integer.MIN_VALUE;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		dish = new int[N];
		kind = new boolean[d + 1];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			dish[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < N; i++) {
			int count = 1;
			Arrays.fill(kind, false); 
			for (int j = i; j < (i + k) ; j++) { 
				if (!kind[dish[j % N]]) {
					kind[dish[j % N ]] = true; 
					count++; 
					if ( dish[j % N ] == c) {
						count --;
					}
				}

			}
			if ( count == k+1) {
				answer =count;
				break;
			}
			answer = Math.max(answer, count);
		}
		
		bw.write(answer + "\n");
		br.close();
		bw.flush();
		bw.close();
		

	}
}