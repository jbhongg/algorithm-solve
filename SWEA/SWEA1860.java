package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SWEA1860 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			st = new StringTokenizer(br.readLine());
			boolean flag = false;
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int time = M;
            int num = K;
            int sum = 0;
            int[] arr = new int[N];
            for(int i=0; i<N; i++) {
            	arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            for(int i=0; i<N; i++) {
            	sum = K * (arr[i]/M);
            	if(sum < i+1) {
            		flag = false;
            		break;
            	}
            	flag = true;
            }
            if(flag) {
            	bw.write("#" + test_case + " Possible" + '\n');
            }
            else {
            	bw.write("#" + test_case + " Impossible" + '\n');
            }
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
