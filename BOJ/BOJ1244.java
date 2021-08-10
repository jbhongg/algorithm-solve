package com.ssafy.hw09;

import java.util.Scanner;

public class BOJ1244{
	static int idx;
	static int num;
	static int[] stat;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		stat = new int[num+1]; //전구를 1번부터 하기위해서 배열의 크기를 +1
		for(int i =1; i<stat.length; i++) {
			stat[i] = sc.nextInt();
		}
		int pnum = sc.nextInt();
		for(int i=0; i<pnum; i++) {
			int p = sc.nextInt();
			idx = sc.nextInt(); 
			if(p == 1) {
				man(idx);
			}
			else if(p == 2) {
				woman(0); 
			}
		}
		for(int i =1; i<stat.length; i++) {
			System.out.print(stat[i] + " ");
             //한줄에 20개씩 출력
	 		if(i%20 == 0) {
				System.out.println();
			}
		}
	}
	
	public static void man(int n) {
		if(n > num) { //배수가 전구의 수보다 크면 종료
			return;
		}
        //전구 바꾸기
		if(stat[n] == 1) { 
			stat[n] = 0;
		}
		else {
			stat[n] = 1;
		}
        // 배수를 가지고 재귀
		man(n + idx);
	}
	
	public static void woman(int n) {
        //양옆이 전구라면
		if(idx + n <= num && idx - n >= 1) {
            //양옆이 서로 같으면 바꿈
			if(stat[idx + n] == 1 && stat[idx - n] == 1) {
				stat[idx + n] = 0;
				stat[idx - n] = 0;
			}
			else if(stat[idx + n] == 0 && stat[idx - n] == 0) {
				stat[idx + n] = 1;
				stat[idx - n] = 1;
			}
            // 서로 다르면 종료
			else {
				return;
			}
		}
        //양옆이 전구가 아니면 종료
		else {
			return;
		}
        //양옆이 전구고 같으면 양쪽으로 한칸씩 늘려서 재귀
		woman(n+1);
	}

}
