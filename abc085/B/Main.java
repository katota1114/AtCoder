import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] d = new int[n];

        for (int i = 0; i < n; i++) {
            d[i] = sc.nextInt();
        }

        Arrays.sort(d);
        int current = Integer.MAX_VALUE;
        int count = 0;

        for (int i = d.length - 1; i >= 0; i--) {
            if (d[i] < current) {
                current = d[i];
                count++;
            }
        }
        System.out.println(count);
    }
}
