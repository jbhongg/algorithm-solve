package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA1859 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			long sum = 0, answer = 0, buy = 0;
			ArrayList<Long> arr = new ArrayList<Long>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr.add(Long.parseLong(st.nextToken()));
			}
			for (int i = 0; i < N - 1; i++) {
				int j = i+1;
				long temp = -1;
				sum = 0;
				while (true) {
					if (arr.get(i) <= arr.get(j)) {
						if (temp < arr.get(j)) {
							temp = arr.get(j);
							for (int k = i; k < j; k++) {
								sum = sum + arr.get(k);
								buy++;
							}
							i = j;
						}	
					}
					j++;
					if (j >= N) {
						break;
					}
				}
				answer = answer + ((buy * arr.get(i)) - sum);
				buy = 0;
			}
			bw.write("#" + test_case + " " + answer + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
