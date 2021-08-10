package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ2477 {
	
	static class Pair{
		int x;
		int y;
		
		public Pair() {
			
		}
		
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int K, answer = 0;
		boolean flag = false;
		ArrayList<Pair> p = new ArrayList<Pair>();
		K = Integer.parseInt(st.nextToken());
		for (int i = 0; i < 6; i++) {
			st = new StringTokenizer(br.readLine());
			p.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		for (int i = 0; i < 3; i++) {
			if (p.get(i).x == p.get(i+2).x && p.get(i+1).x == p.get(i+3).x) {
				answer = ((p.get(i).y + p.get(i+2).y) * (p.get(i+1).y + p.get(i+3).y)) - (p.get(i+1).y * p.get(i+2).y);
				flag = true;
				break;
			}
		}
		
		if (flag) {
			bw.write(answer*K + "\n");
		}
		else {
			if (p.get(0).x == p.get(2).x) {
				answer = ((p.get(0).y + p.get(2).y) * (p.get(1).y + p.get(5).y)) - (p.get(0).y * p.get(1).y);
				bw.write(answer*K + "\n");
			}
			else if(p.get(0).x == p.get(4).x && p.get(1).x == p.get(5).x){
				answer = ((p.get(0).y + p.get(4).y) * (p.get(1).y + p.get(5).y)) - (p.get(0).y * p.get(5).y);
				bw.write(answer*K + "\n");
			}
			else {
				answer = ((p.get(0).y + p.get(4).y) * (p.get(3).y + p.get(5).y)) - (p.get(4).y * p.get(5).y);
				bw.write(answer*K + "\n");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
