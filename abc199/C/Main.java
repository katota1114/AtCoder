import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();

        int q = sc.nextInt();

        for (int i = 0; i < q; i++) {
            int t_i = sc.nextInt();
            int a_i = sc.nextInt();
            int b_i = sc.nextInt();
            if (t_i == 1) {
                char tmp = s[a_i - 1];
                s[a_i - 1] = s[b_i - 1];
                s[b_i - 1] = tmp;
            } else {
                for (int j = 0; j < n; j++) {
                    char tmp = s[j];
                    s[j] = s[j + n];
                    s[j + n] = tmp;
                }
            }
        }
        System.out.println(s);
    }
}
