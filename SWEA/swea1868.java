package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class swea1868 {
    static int N;
    static char[][] map;
    static boolean[][] visited;
    static int[] dc = {-1,-1,0,1,1,1,0,-1};
    static int[] dr = {0,1,1,1,0,-1,-1,-1};
    static int cnt;
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
         
        for (int testcase = 1; testcase <= T; testcase++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            map = new char[N][N];
            visited = new boolean[N][N];
             
            for (int i = 0; i < N; i++) {
            	st = new StringTokenizer(br.readLine());
            	String s = st.nextToken();
            	for(int j=0; j<s.length(); j++) {
            		map[i][j] = s.charAt(j);
            	}
            }
             
            cnt = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(map[i][j] == '.' && check(i, j) == 0) {
                    	cnt++;
                        bfs(i, j);
                    }
                }
            }
             
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(map[i][j] == '.') {
                    	cnt++;
                    }
                }
            }
            bw.write("#" + testcase + " " + cnt + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
         
    }
     
    public static void bfs(int c, int r) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {c, r});
        visited[c][r] = true;
         
        int[] p;
        while(!q.isEmpty()) {
            p = q.poll();
             
            map[p[0]][p[1]] = '0';
            int nc, nr;
            for (int i = 0; i < 8; i++) {
                nc = p[0] + dc[i];
                nr = p[1] + dr[i];
                 
                int cnt = check(nc, nr);
                if(nc >= 0 && nc < N && nr >= 0 && nr < N && !visited[nc][nr] && map[nc][nr] == '.') {
                    if(cnt == 0) {
                        q.offer(new int[] {nc, nr});
                        visited[nc][nr] = true;
                    }
                    else {
                    	map[nc][nr] = (char) (cnt + '0');
                        visited[nc][nr] = true;
                    }
                }
            }
             
        }       
    } 
     
    public static int check(int c, int r) {
        int cnt = 0;
        int nc, nr;
        for (int i = 0; i < 8; i++) {
            nc = c + dc[i];
            nr = r + dr[i];
             
            if(nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == '*')
                cnt++;
        }
        return cnt;
    }
     
}