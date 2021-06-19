import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int y = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                if (10000 * i + 5000 * j + 1000 * (n - i - j) == y) {
                    System.out.printf("%d %d %d\n", i, j, n - i - j);
                    return;
                }
            }
        }
        System.out.println("-1 -1 -1");
    }
}
