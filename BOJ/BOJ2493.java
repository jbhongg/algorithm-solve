package com.ssafy.hw12;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ2493 {
	
	static class pair{
		int x;
		int y;
		public pair() {}
		public pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Stack<pair> top = new Stack<pair>();
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			int h = Integer.parseInt(st.nextToken());
			while (!top.isEmpty()) {
				if (top.peek().y > h) {
					bw.write(top.peek().x + " ");
					break;
				}
				top.pop();
			}
			if (top.isEmpty()) {
				bw.write("0 ");
			}
			top.push(new pair(i, h));
		}
		br.close();
		bw.flush();
		bw.close();
	}

}