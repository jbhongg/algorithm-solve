package com.ssafy.day01;

import java.util.Scanner;

class pair {
	int x;
	int y;
	
	pair() {}
	
	pair(int x, int y) {
		this.x = x;
		this.y = y;
		}
	}

public class SWEA1247 {
	static int customer;
	static int min;
	static boolean visit[];
	static pair[] cus;
	static pair company = new pair();
	static pair home = new pair();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			min = Integer.MAX_VALUE;
            customer = sc.nextInt();
            cus = new pair[customer];
            visit = new boolean[customer];
            company.x = sc.nextInt();
            company.y = sc.nextInt();
            home.x = sc.nextInt();
            home.y = sc.nextInt();
            for(int i=0; i<cus.length; i++) {
            	cus[i] = new pair();
            	cus[i].x = sc.nextInt();
            	cus[i].y = sc.nextInt();
            }
            
            solve(0, company.x, company.y,0);
            
            System.out.println("#" + test_case + " " + min );
		}
	}
	public static void solve(int num, int x, int y, int dis) {
		if(num == customer) {
			dis = dis + (Math.abs(x-home.x) + Math.abs(y-home.y));
			min = Math.min(min, dis);
			return ;
		}
		for(int i=0; i<customer; i++) {
			if(!visit[i]) {
				visit[i] = true;
				solve(num+1, cus[i].x, cus[i].y, dis + (Math.abs(x-cus[i].x) + Math.abs(y-cus[i].y)));
				visit[i] = false;
			}
		}
	}

}
