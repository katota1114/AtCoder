import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int min = 0;
        int max = 2000;


            for (int j = 0; j < n; j++) {
                int a = sc.nextInt();
                if (min < a) {
                    min = a;
                }
            }


            for (int j = 0; j < n; j++) {
                int a = sc.nextInt();
                if (max > a) {
                    max = a;
                }
            }
        if (max-min+1 > 0) {
            System.out.println(max - min + 1);
        } else {
            System.out.println(0);
        }

    }
}
