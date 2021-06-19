import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        int aliceScore = 0;
        int bobScore = 0;
        boolean isAliceTurn = true;
        for (int i = a.length - 1; i >= 0; i--) {
            if (isAliceTurn) {
                aliceScore += a[i];
                isAliceTurn = false;
            } else {
                bobScore += a[i];
                isAliceTurn = true;
            }
        }
        System.out.println(aliceScore - bobScore);
    }
}
