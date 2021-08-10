package com.ssafy.hw09;

import java.util.Scanner;

public class SWEA1289{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			String s = sc.next();
			int count = 0;
			boolean check = false; //숫자의 변화가 있었는지 확인하기 위한 변수
			for(int i =0; i<s.length(); i++) {
				if(check == false && s.charAt(i) == '1') {
					count++;
					check = true;
				}
				else if(check == true && s.charAt(i) == '0') {
					count++;
					check = false;
				}
			}
			System.out.println("#" + test_case + " " + count);
		}
	}

}
