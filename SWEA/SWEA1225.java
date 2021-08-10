package com.ssafy.day01;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA1225 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<Integer>();
		int T;
		for(int test_case = 1; test_case<=10; test_case++) {
			q.clear();
			T=sc.nextInt();
			for(int i=0; i<8; i++) {
				q.add(sc.nextInt());
			}
			while(true) {
				if((q.peek() - 1) <= 0) {
					q.poll();
					q.add(0);
					break;
				}
				q.add(q.poll()-1);
				if(q.peek() - 2 <= 0) {
					q.poll();
					q.add(0);
					break;
				}
				q.add(q.poll()-2);
				if(q.peek() - 3 <= 0) {
					q.poll();
					q.add(0);
					break;
				}
				q.add(q.poll()-3);
				if(q.peek() - 4 <= 0) {
					q.poll();
					q.add(0);
					break;
				}
				q.add(q.poll() - 4);
				if(q.peek() - 5 <= 0) {
					q.poll();
					q.add(0);
					break;
				}
				q.add(q.poll() - 5);
			}
			System.out.print("#" + T + " ");
			for(int i : q) {
				System.out.print(i + " ");
			}
			System.out.println();
		}
	}
}
