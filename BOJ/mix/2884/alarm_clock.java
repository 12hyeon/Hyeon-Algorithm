package BOJ;
import java.util.Scanner;

public class alarm_clock {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int hour, sec;
        hour = sc.nextInt();
        sec = sc.nextInt();

        if (sec-45 < 0) { // 0분 미만 방지
            if (hour == 0) { // 24시 초과 방지
                hour = 23;
            } else {
                hour -= 1;
            }
            sec += 15;
        } else {
            sec -= 45;
        }

        System.out.print(hour+" "+sec);
        sc.close();
    }
}