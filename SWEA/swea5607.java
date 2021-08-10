package com.ssafy.ct;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class swea5607 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int test_case = 1; test_case <= T; test_case++) {
        	st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            long fac[] = new long[N + 1];
            fac[0] = 1;
            for (int i = 1; i <= N; i++) {
            	fac[i] = (fac[i - 1] * i) % 1234567891;
            }

            long a = (fac[R] * fac[N - R]) % 1234567891;
            long b = solve(a, 1234567891 - 2);
            
            bw.write("#" + test_case + " " + (fac[N] * b) % 1234567891 + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }

    public static long solve(long a, int b) {
        if (b == 0) {
        	return 1;
        }
        long temp = solve(a, b / 2);
        long num = (temp * temp) % 1234567891;
        if (b % 2 == 0) {
        	return num;
        }
        else {
        	return (num * a) % 1234567891;
        }
    }
}