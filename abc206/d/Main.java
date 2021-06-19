import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int count = 0;

        for (int i = 0; i < a.length / 2; i++) {
            if (a[i] != a[a.length - 1 - i]) {
                replace(a, a[i], a[a.length - 1 - i]);
                count++;
            }
        }

        System.out.println(count);
    }

    public static void replace(int[] array, int from, int to) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == from) {
                array[i] = to;
            }
        }
    }
}
