import java.util.Scanner;
import java.util.stream.IntStream;

public class Even2PrimesNaive {
    private static final Scanner sc = new Scanner(System.in);

    private static boolean isPrime(final int x) {
        for (int i = 2; i < x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    private static int solve(final int x) {
        int answer = 0;
        for (int j = 2; j <= x / 2; j++) {
            if (isPrime(j) && isPrime(x - j)) {
                answer++;
            }
        }
        return answer;
    }

    public static void main(final String[] args) {
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            final int x = sc.nextInt();
            System.out.println(solve(x));
        }
    }
}
