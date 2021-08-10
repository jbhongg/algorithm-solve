package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ18512 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int a = 0,b = 0;
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int px = Integer.parseInt(st.nextToken());
		int py = Integer.parseInt(st.nextToken());
		boolean flag= false;
		while((px + x*a) != (py + y*b)) {
			if(a == 100 || b == 100) {
				flag = true;
				break;
			}
			if(px + x*a > py + y*b) {
				b++;
			}
			else {
				a++;
			}
		}
		if(flag) {
			
		}
		else {
			bw.write((px + x*a) + "\n");
		}
		br.close();
		bw.flush();
		bw.close();;
	}	
}
