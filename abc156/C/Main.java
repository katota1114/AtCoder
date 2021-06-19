import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
        }

        int min = Integer.MAX_VALUE;

        for (int i = 1; i < 101; i++) {
            int tmp = 0;
            for (int j = 0; j < x.length; j++) {
                tmp += (x[j] - i) * (x[j] - i);
            }

            if (tmp < min) {
                min = tmp;
            }
        }
        System.out.println(min);
    }
}
