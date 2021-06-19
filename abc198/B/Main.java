import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int nLen = n.length();

        // 末尾の0を取り去る
        while (n.endsWith("0")) {
            nLen--;
            n = n.substring(0, nLen);
        }

        // 回文になっているかをチェックする
        while (nLen > 1) {
            char first = n.charAt(0);
            char last = n.charAt(nLen - 1);
            if (first != last) {
                System.out.println("No");
                return;
            }
            n = n.substring(1, nLen - 1);
            nLen = n.length();
        }

        System.out.println("Yes");
    }
}
