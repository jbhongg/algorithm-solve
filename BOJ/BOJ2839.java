package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2839 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		for(int i = N/5; i>=0; i--) {
			//5로 나눠서 나머지가 0이면 몫 출력 후 종료 
			if(N-(5*i) == 0) {
				bw.write(i + "\n");
				break;
			}
			//5로 나눠서 나머지가 0이 아니면
			else {
				//남은 값을 3으로 나눠서 0이면 이전 5로 나눈 몫 + 남은 값을 3으로 나눈 몫 출력 후 종료
				if((N-(5*i))%3 == 0)
				{
					bw.write(i+((N-(5*i))/3) + "\n");
					break;
				}
			}
			//끝까지 for문이 돌면 나누어 떨어지지 않는다는 소리이므로 -1 출력
			if(i==0) {
				bw.write(-1 + "\n");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
