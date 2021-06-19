import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int day = 0;
        int sum = 0;
        do {
            day++;
            sum += day;
        } while (sum < n);
        System.out.println(day);
    }
}
