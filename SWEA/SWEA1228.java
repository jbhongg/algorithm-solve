package com.ssafy.day01;

import java.util.LinkedList;
import java.util.Scanner;

public class SWEA1228 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int test_case = 1; test_case <= 10; test_case++) {
			LinkedList<Integer> arr = new LinkedList<Integer>();
			int N = sc.nextInt();
			for(int i=0; i<N; i++) {
				arr.add(sc.nextInt());
			}
			int c = sc.nextInt();
			int count =0;
			while(count != c) {
				sc.next();
				count ++;
				int idx = sc.nextInt();
				int num = sc.nextInt();
				for(int i = 0; i<num; i++) {
					arr.add(idx, sc.nextInt());
					idx++;
				}
			}
			
			System.out.print("#" + test_case + " ");
            for (int i = 0; i < 10; i++) {
                System.out.print(arr.poll()+" ");
            }
            System.out.println();
		}
	}

}
