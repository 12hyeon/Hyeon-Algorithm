package BOJ;

import java.util.Scanner;
// a + bxcnt > cxcnt => a > (c-b)cnt => a/(c-b) > cnt
class break_even {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int fix_cost, var_cost, price;
        fix_cost = sc.nextInt();
        var_cost = sc.nextInt();
        price = sc.nextInt();

        if (price - var_cost <= 0) // 손익분기점이 없음
            System.out.println(-1);
        else// 판매가격에서 1대당 사용되는 가격을 제외한 상태에서 고정비용을 해결하는 개수
            System.out.println(fix_cost/(price - var_cost)+1);
    }
}