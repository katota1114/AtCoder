import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int c = sc.nextInt();

        int[] b = new int[m];
        for (int i = 0; i < b.length; i++) {
            b[i] = sc.nextInt();
        }

        int[][] a = new int[n][m];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int correct = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += a[i][j] * b[j];
            }
            sum += c;
            if (sum > 0) {
                correct++;
            }
        }
        System.out.println(correct);
    }
}
