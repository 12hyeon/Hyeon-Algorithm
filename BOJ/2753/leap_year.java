package BOJ;

import java.util.Scanner;

public class leap_year {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        if ((num%4 == 0) && (num%100 != 0) || (num%400 == 0))
            System.out.print(1);
        else
            System.out.print(0);
        sc.close();
    }
}