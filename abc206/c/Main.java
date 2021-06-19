import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++) {
            int input = sc.nextInt();
            int count = 1;
            if (map.containsKey(input)) {
                count += map.get(input);
            }
            map.put(input, count);
        }

        int count = n * (n - 1) / 2;
        Iterator<Integer> iterator = map.keySet().iterator();
        while (iterator.hasNext()) {
            int key = iterator.next();
            int value = map.get(key);
            count -= value * (value - 1) / 2;
        }

        System.out.println(count);
    }
}
