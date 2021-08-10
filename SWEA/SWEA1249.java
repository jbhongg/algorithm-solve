package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

 
public class SWEA1249 {
    static int[] dc = {-1,0,1,0};
    static int[] dr = {0,1,0,-1};
    static int n;
    static int[][] map;
    static int min;
    static boolean[][] visit;
    static int[][] answer;
    
    static class pair {
        int x;
        int y;
        
        public pair() {
        	
        }
        
        public pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
         
        for(int test_case=1; test_case<=T; test_case++){
        	st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            map = new int[n][n];
            for(int i=0; i<n; i++){
            	st = new StringTokenizer(br.readLine());
                String temp = st.nextToken();
                for(int j=0; j<n; j++){
                    map[i][j] = temp.charAt(j) - '0';
                }
            }
 
            min = Integer.MAX_VALUE;
            visit = new boolean[n][n];
     
            answer = new int[n][n];
            for(int i=0; i<n; i++) {
                Arrays.fill(answer[i], Integer.MAX_VALUE);
            }
            answer[0][0] = 0;
            bfs(0,0);
            
            bw.write("#" + test_case + " " + min + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
 
    private static void bfs(int x, int y){
        Queue<pair> q = new LinkedList<>();
 
        q.offer(new pair(x,y));
        visit[x][y] = true;
        while(!q.isEmpty()){
            pair p = q.poll();
            int c = p.x;
            int r = p.y;
 
            if(c == n-1 && r == n-1) {
				if(min > answer[n-1][n-1]) {
                	min = answer[n-1][n-1];
                }
            }

            if(min <= answer[c][r]) {
                continue;
            }
            for(int i=0; i<4; i++){
                int nc = c + dc[i];
                int nr = r + dr[i];
                if(nc >= 0 && nc < n && nr >= 0 && nr < n){
                    if(!visit[nc][nr] || answer[nc][nr] > answer[c][r] + map[nc][nr]){
                    	visit[nc][nr] = true;
                        answer[nc][nr] = answer[c][r] + map[nc][nr];
                        q.offer(new pair(nc, nr));
                    }
                }
            }
        }
    }
}