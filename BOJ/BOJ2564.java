package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2564 {
	static int m,n;
	static int store;
	static int[] stores;
	static int dir,len, sum, max, min;
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		m=Integer.parseInt(st.nextToken());
		n=Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		store = Integer.parseInt(st.nextToken());
		stores=new int[store];
		for (int i = 0; i < store; i++) {
			st=new StringTokenizer(br.readLine());
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			
			if(a==1) {
				stores[i]=b;
			}else if(a==2) {
				stores[i]=m+n+(m-b);
			}else if(a==3) {
				stores[i]=m+n+m+(n-b);
			}else {
				stores[i]=m+b;
			}
			
		}
		
		st=new StringTokenizer(br.readLine());
		dir=Integer.parseInt(st.nextToken());
		int x=Integer.parseInt(st.nextToken());
		if(dir==1) {
			len=x;
		}else if(dir==2) {
			len=m+n+(m-x);
		}else if(dir==3) {
			len=m+n+m+(n-x);
		}else {
			len=m+x;
		}
		for (int i = 0; i < store; i++) {
			if(len>stores[i]) {
				max = len;
			}
			else {
				max = stores[i];
			}
			if(len<=stores[i]) {
				min = len;
			}
			else {
				min = stores[i];
			}
			sum+=Math.min(max-min, 2*(m+n)-max+min);
		}
		bw.write(sum + "\n");
		br.close();
		bw.flush();
		bw.close();	
	}
}