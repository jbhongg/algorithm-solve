package com.ssafy.ct;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class swea3238
{
        public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
         
        for (int test_case = 1; test_case <= T; test_case++) {
             st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            long R = Long.parseLong(st.nextToken());
            long p = Long.parseLong(st.nextToken());
            long[] arr = new long[(int) (p+1)];
            arr[0] = 1;
            for (int i = 1; i < p+1; i++) {
                arr[i] = arr[i-1] * i % p;
            }
            long answer = 1;
            while(N != 0 || R != 0) {
                long n = N % p;
                long r = R % p;
                N /= p;
                R /= p;
                if(n < r) {
                	answer = 0;
                    break;
                }else {
                	answer *= arr[(int) n] * solve(arr[(int) (n - r)] * arr[(int) r], p-2, p) % p;
                	answer %= p;
                }
            }
            bw.write("#" + test_case + " " + answer + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
 
    public static long solve(long x, long y, long p) {
        long answer = 1;
        x = x % p;
        while(y>0) {
            if(y%2 == 1) answer = (answer * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return answer;
    }
 
}
