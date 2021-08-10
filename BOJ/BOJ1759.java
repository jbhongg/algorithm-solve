package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ1759 {
	static char[] s;
	static int L, C;
	static char[] col = {'a','e','i','o','u'};
	static int[] con = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	static ArrayList<char[]> answer=new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		s = new char[C];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			s[i] = st.nextToken().charAt(0);
		}
		
		solve(0,0, new char[L]);
		
		Collections.sort(answer,new Comparator<char[]>() {

			@Override
			public int compare(char[] o1, char[] o2) {
				for (int i = 0; i < o1.length; i++) {
					if(o1[i]==o2[i]) {
						continue;
					}
					return o1[i]-o2[i];
				}
				return 0;
			}
		});
		for (int i = 0; i < answer.size(); i++) {
			bw.write(answer.get(i));
			bw.write("\n");
		}

		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int idx, int k, char[] sel) {
		if(k == L) {
			int cnt_col=0;
			int cnt_con=0;
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < col.length; j++) {
					if(sel[i]==col[j]) {
						cnt_col++;
					}
				}
				for (int j = 0; j < con.length; j++) {
					if(sel[i]==con[j]) {
						cnt_con++;
					}
				}
			}
			
			char[] tmp = new char[L];
			if(cnt_col >= 1 && cnt_con >= 2) {
				for (int i = 0; i < L; i++) {
					tmp[i]=sel[i];
				}
				Arrays.sort(tmp);
				answer.add(tmp);
			}
			return;
		}
		if(idx==C) {
			return;
		}
		
		sel[k]=s[idx];
		solve(idx+1,k+1,sel);
		solve(idx+1,k,sel);
	}

}
