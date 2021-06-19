import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int nPlusTax = (int) Math.floor(1.08 * n);
        if (nPlusTax < 206) {
            System.out.println("Yay!");
        } else if (nPlusTax > 206) {
            System.out.println(":(");
        } else {
            System.out.println("so-so");
        }
    }
}
