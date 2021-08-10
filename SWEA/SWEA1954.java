package com.ssafy.hw10;

import java.util.Scanner;

public class SWEA1954{
	static int num;
	static  int[][] map;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			num = sc.nextInt();
			map = new int[num][num];

			solve(0,num,1);
		
			System.out.println("#" + test_case);
			
			for(int[] i : map) {
				for(int j : i) {
					System.out.print(j + " ");
				}
				System.out.println();
			}
		}
	}
	public static void solve(int x, int edge, int n) {
		//num의 수가 홀수일때만 가장자리 한칸이 존재 짝수일 때는 num/2 만큼 사각형이 존재
		if (x == (num / 2)) {
			//홀수일때 존재하는 정 가운데 한칸의 값은 num*num
			if(num % 2 == 1) {
				map[num/2][num/2] = num*num;
			}
			return;
		}
		//정사각형 중 위쪽 변의 수 채우기
		for (int j = x; j < edge; j++) {
			map[x][j] = n;
			n++;
		}
		//정사각형 중 오른쪽 변의 수 채우기
		for (int i = x + 1; i < edge; i++) {
			map[i][edge - 1] = n;
			n++;
		}
		//정사각형 중 오른쪽 변의 수 채우기
		for (int j = edge - 2; j >= x; j--) {
			map[edge - 1][j] = n;
			n++;;
		}
		//정사각형 중 왼쪽 변의 수 채우기
		for (int i = edge - 2; i >= x + 1; i--) {
			map[i][x] = n;
			n++;
		}
		
		//시작위치를 한 행 증가하고 행렬의 범위를 하나 줄이고, 다음 채울 숫자를 넘겨주며 재귀
		solve(x + 1, edge - 1, n);
	}

}