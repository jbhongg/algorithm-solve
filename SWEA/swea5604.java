package com.ssafy.ct;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class swea5604 {

	static int T;
	static long A, B, S;
	static HashMap<Long, Long> m=new HashMap<Long, Long>();
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
		
		m.clear();
		for (int i = 1; i < 17; i++) { 
			long v=pow10(0L+i);
			m.put((v-1L), h(v-1L));
		}

		int T = Integer.parseInt(st.nextToken());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine());
			A=Long.parseLong(st.nextToken());
			B=Long.parseLong(st.nextToken());
			S=cal(B,A);
			bw.write("#" + test_case + " " + S + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static long h(long n) {
		long len=len(n)+1L;
		return ((45L)*(len)*(1L+n))/(10L);
	}
	public static long cal(long B,long A){
		if(A<=1){
			return f(B);
		}else if(A==B){
			return f(B)-f(A-1);  
		}else{
			return f(B)-f(A-1);
		}
	}
	public static long g(long n){
		if(n<=9){
			return e(n);
		}else{
			long v=pow10(len(n));
			return (n/v)*(n%v+1L)+ f(n%v);
		}
	}
	public static long f(long n) {
		if(m.containsKey(n)) {
			return m.get(n);
		}else if(n<=9){
			return e(n);
		}else{
			long v=pow10(len(n));
			m.put(n, f(n-1L-n%v)+g(n));
			return m.get(n);
		}
	}
	public static long e(long n){
		return n*(n+1L)/2L;
	}
	public static long len(long n){
		return 0L+(n+"").length()-1;
	}
	public static long pow10(long n){
		return (long)Math.pow(10, n);
	}
}

