package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class SWEA1233 {
	static int N;
	static String[] node;
	static int[][] edge;
	static boolean[] visit;
	static boolean flag;
	static Stack<Integer> s = new Stack<Integer>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
				
		for(int test_case = 1; test_case <= 10; test_case++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			node = new String[N+1];
			edge = new int[N+1][N+1];
			visit = new boolean[N+1];
			flag = true;
			s.clear();
			
			for(int i = 1; i<=N; i++) {
				st = new StringTokenizer(br.readLine());
				int parent = Integer.parseInt(st.nextToken());
				node[i] = st.nextToken();
				for(int j =0; j<2; j++) {
					if(st.hasMoreTokens()) {
						int child = Integer.parseInt(st.nextToken());
						edge[parent][child] = 1;
					}
				}
			}
			dfs(1);
			if(s.size() > 1) {
				flag = false;
			}
			if(flag) {
				bw.write("#" + test_case + " 1\n");
			}
			else {
				bw.write("#" + test_case + " 0\n");
			}
			
		}
		br.close();
		bw.flush();
		bw.close();
	}
	public static void dfs(int k) {
		if(flag == false) {
			return;
		}
		visit[k] = true;
		for(int i=k+1; i<=N; i++) {
			if(edge[k][i] == 1 && visit[i] == false) {
				dfs(i);
			}
		}
		op(node[k]);
	}
	public static void op(String node) {
		if(node.equals("+") || node.equals("-") || node.equals("*") || node.equals("/")) {
			if(s.size() < 2) {
				flag = false;
				return;
			}
			int node1 = s.pop();
			int node2 = s.pop();
			if(node.equals("+")) {
				s.add(node1 + node2);
			}
			if(node.equals("-")) {
				s.add(node1 - node2);
			}
			if(node.equals("*")) {
				s.add(node1 * node2);
			}
			if(node.equals("/")) {
				if(node2 == 0) {
					node2 = 1;
				}
				s.add(node1 / node2);
			}
		}
		else {
			s.add(Integer.parseInt(node));
		}
	}

}
