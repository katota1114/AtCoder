import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean isApproved = true;

        for (int i = 0; i < n; i++) {
            int a_i = sc.nextInt();
            if (a_i % 2 == 0) {
                // 偶数
                if (a_i % 3 == 0 || a_i % 5 == 0) {
                    continue;
                } else {
                    isApproved = false;
                    break;
                }
            } else {
                // 奇数
                continue;
            }
        }

        if (isApproved) {
            System.out.println("APPROVED");
        } else {
            System.out.println("DENIED");
        }
    }
}
