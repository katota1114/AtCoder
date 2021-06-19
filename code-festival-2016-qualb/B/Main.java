import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        char[] s = sc.next().toCharArray();

        int passed = 0;
        int passed_foreign = 0;

        for (int i = 0; i < s.length; i++) {
            if (s[i] == 'a') {
                // 国内の学生
                if (a+b > passed) {
                    System.out.println("Yes");
                    passed++;
                    continue;
                }
            } else if (s[i] == 'b') {
                // 海外の学生
                if (a+b > passed && b > passed_foreign) {
                    System.out.println("Yes");
                    passed++;
                    passed_foreign++;
                    continue;
                }
            }
            System.out.println("No");
        }
    }
}
