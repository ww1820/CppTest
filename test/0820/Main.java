import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String[] heights_ = str.split(" ");
        int[] heights = new int[heights_.length];
        for (int i = 0; i < heights_.length; i++) {
            String temp = heights_[i];
            temp = temp.replace(",", "");
            heights[i] = Integer.parseInt(temp);
        }
        int n = heights.length;
        int k = n / 2;
        for (int i = k; i >= 1; i--) {
            if (n % i != 0)
                continue;
            if (check(heights, i)) {
                k = i;
                break;
            }
        }
        if (k == 0)
            k = 1;
        System.out.println("lenth:" + "  " + String.valueOf(k));
        for (int i = 0; i < n / k; i++) {
            System.out.print("[");
            for (int j = 0; j < k; j++) {
                System.out.print(heights[j + i * k]);
                if (j != k - 1)
                    System.out.print(", ");
            }
            System.out.println("]");
        }
    }

    public static boolean check(int[] matrix, int k) {
        if (k == 1)
            return true;
        int gap = matrix[1] - matrix[0];
        for (int i = 1; i < matrix.length; i++) {
            if (i % k == 0) {
                gap = matrix[i + 1] - matrix[i];
                continue;
            }
            if (matrix[i] - matrix[i - 1] != gap) {
                return false;
            }
        }
        return true;
    }
}