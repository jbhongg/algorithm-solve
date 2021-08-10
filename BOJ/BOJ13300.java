package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ13300 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()); 
		int K = Integer.parseInt(st.nextToken()); 
		int count = 0;
		
		int[] boy = new int[6];
		int[] girl = new int[6];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int S = Integer.parseInt(st.nextToken()); 
			int Y = Integer.parseInt(st.nextToken()); 
			//남학생
			if (S == 1) {
				if (boy[Y - 1] == K) {
					boy[Y - 1] = 0;
					count++;
				}
				boy[Y - 1]++;
			}
			//여학생
			else {
				if (girl[Y - 1] == K) {
					girl[Y - 1] = 0;
					count++;
				}
				girl[Y - 1]++;
			}

		}
		for (int i = 0; i < 6; i++) {
			if (boy[i] != 0) {
				count++;
			}
			if (girl[i] != 0) {
				count++;
			}
		}
		bw.write(count + "\n");
		br.close();
		bw.flush();
		bw.close();
	}

}
