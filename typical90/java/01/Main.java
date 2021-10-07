import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int min = 0;
        int max = l;

        while (max - min > 1 && max > min) {
            int target = (max - min) / 2 + min;
            System.out.printf("isDividable(a, %d, %d)\n", k, target);
            if (isDividable(a, k, target, l)) {
                min = target;
            } else {
                max = target;
            }
        }

        System.out.println("max = " + max + ", min = " + min);
    }

    // k+1個以上の「長さm以上のピース」に分割可能か
    private static boolean isDividable(int[] a, int k, int m, int l) {
        int count = 0;
        int current_size = 0;
        int prev = 0;
        for (int i = 0; i < a.length; i++) {
            current_size += a[i] - prev;
            prev = a[i];
            if (current_size < m) {
                count++;
                current_size = 0;
            }
        }

        if (count > k) {
            return true;
        } else {
            return false;
        }
    }
}
