package com.ssafy.day01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2580 {
   static int[][] map;
   static boolean[][] xline;
   static boolean[][] yline;
   static boolean[][] sqare;
   static int N;
   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      map = new int[9][9];
      xline = new boolean[9][10];
      yline = new boolean[9][10];
      sqare = new boolean[9][10];
      for(int i=0;i<9;i++) {
         String input = br.readLine();
         for(int j=0;j<9;j++) {
            map[i][j] = input.charAt(j)-'0';
            if(map[i][j] == 0)N++;
            else {
               xline[i][map[i][j]] = true;
               yline[j][map[i][j]] = true;
               sqare[getSqare(j,i)][map[i][j]] = true;
            }
         }
      }
      StringBuilder sb = new StringBuilder();
      solves(0);
      for(int i=0;i<9;i++) {
         for(int j=0;j<9;j++) {
            sb.append(map[i][j]);
         }
         sb.append("\n");
      }
      System.out.println(sb);
   }
   public static int getSqare(int x, int y) {
      for(int i=1;i<=3;i++) {
         for(int j=1;j<=3;j++) {
            if(x<i*3&&y<j*3) {
               return (j-1)*3+i-1;
            }
         }
      }
      return 0;
   }
   public static boolean solves(int n) {
      if(n==N) {
         return true;
      }
      
      for(int i=0;i<9;i++) {
         for(int j=0;j<9;j++) {
            if(map[i][j]==0) {//수도쿠가 빈칸이면
               for(int k=1;k<10;k++) {
                  if(!xline[i][k]&&!yline[j][k]&&!sqare[getSqare(j,i)][k]) {
                     map[i][j] = k;
                     xline[i][k] = true;
                     yline[j][k] = true;
                     sqare[getSqare(j,i)][k] = true;
                     if(solves(n+1))return true;
                     map[i][j] = 0;
                     xline[i][k] = false;
                     yline[j][k] = false;
                     sqare[getSqare(j,i)][k] = false;
                  }
               }
               return false;
            }
         }
      }
      return false;
   }
}