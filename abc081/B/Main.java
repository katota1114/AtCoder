import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
        }

        boolean isAllOdd = true;
        int count = 0;

        while (true) {
            for (int i = 0; i < a.length; i++) {
                if (a[i] % 2 == 1) {
                    isAllOdd = false;
                    break;
                }
            }

            if (!isAllOdd) {
                break;
            }

            for (int i = 0; i < a.length; i++) {
                a[i] = a[i] / 2;
            }
            count++;
        }

        System.out.println(count);
    }
}
