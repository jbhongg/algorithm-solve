package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA6808 {
	static int[] user1;
	static int[] user2;
	static boolean[] visit;
	static int sum1, sum2, win, lose;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
            st =  new StringTokenizer(br.readLine());
    		boolean[] card = new boolean[19];
    		user1 = new int[9];
    		user2 = new int[9];
    		visit = new boolean[9];
            win = 0;
            lose = 0;
            sum1 = 0;
            sum2 = 0;
            for(int i=0; i<9; i++) {
            	user1[i] = Integer.parseInt(st.nextToken());
            	card[user1[i]] = true;
            }
            
            int idx = 0;
            
            for(int i=1; i<=18; i++) {
            	if(!card[i]) {
            		user2[idx++] = i;
            	}
            }
            
            solve(0);
            
            bw.write("#" + test_case + " " + win + " " + lose + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void solve(int k) {
		if(sum1 > (171/2) || sum2 > (171/2)) {
			int p = 1;
			for(int j=9-k; j>0; j--) {
				p = p*j;
			}
			if(sum1 > sum2) {
				win = win + p;
			}
			else {
				lose = lose + p;
			}
			return;
		}
		for(int i=0; i<9; i++) {
			if(!visit[i]) {
				visit[i] = true;
				if(user1[k] > user2[i]) {
					sum1 = sum1 + user1[k] + user2[i];
					solve(k+1);
					sum1 = sum1 - user1[k] - user2[i];
				}
				else {
					sum2 = sum2 + user1[k] + user2[i];
					solve(k+1);
					sum2 = sum2 - user1[k] - user2[i];
				}
				visit[i] = false;
			}
		}
	}

}
