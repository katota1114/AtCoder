import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int sum = 0;

        for (int i = 0; i < n + 1; i++) {
            int j = i;
            int digit_sum = 0;
            while (j > 0) {
                digit_sum += j % 10;
                j = j / 10;
            }

            if (digit_sum >= a && digit_sum <= b) {
                sum += i;
            }
        }

        System.out.println(sum);
    }
}
