package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA3499{

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            String[] card = new String[N]; //셔플한 카드를 저장하기 위한 변수
            int x = 0; //카드 덱을 반으로 나눴을 때 앞의 카드 덱의 카드가 저장되는 인덱스의 시작 위치 
            int y = 1; //카드 덱을 반으로 나눴을 때 뒤의 카드 덱의 카드가 저장되는 인덱스의 시작 위치 
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++) {
                //카드의 갯수가 짝수이고 반으로 나눈 카드 덱 중 뒤의 카드 덱이라면
            	if(N % 2 == 0 && i >= N/2){
            		card[y] = new String();
            		card[y] = st.nextToken(); //배열에 카드 저장
            		y = y + 2; 				  //다음 카드를 저장할 위치
            	}
				//카드의 갯수가 홀수이고 반으로 나눈 카드 덱 중 뒤의 카드 덱이라면
            	else if(N % 2 == 1 && i > N/2) {
            		card[y] = new String();
            		card[y] = st.nextToken(); //배열에 카드 저장
            		y = y + 2; 				  //다음 카드를 저장할 위치
            	}
				//반으로 나눈 카드 덱 중 앞의 카드 덱이라면
            	else {
            		card[x] = new String();
            		card[x] = st.nextToken(); //배열에 카드 저장
            		x = x + 2; 				  //다음 카드를 저장할 위치
            	}
            }
            for(String s : card) {
            	sb.append(s + " ");
            }
            System.out.print("#" + test_case + " " + sb);
		}
		br.close();
	}

}