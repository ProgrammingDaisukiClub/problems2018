import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Even2Primes {
    private static final Scanner sc = new Scanner(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);
    private static final int MAX_N = 5000000;
    private static boolean isPrime[] = new boolean[MAX_N + 1];

    private static void primeList() {
        Arrays.fill(isPrime, true);
        isPrime[1] = false;
        isPrime[2] = true;
        for (int i = 4; i <= MAX_N; i += 2) {
            isPrime[i] = false;
        }
        for (int i = 3; i * i <= MAX_N; i += 2) {
            if (!isPrime[i]) continue;
            // isPrime[i] = true;
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    public static void main(final String[] args) {
        primeList();
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int x = sc.nextInt();
            int answer = 0;
            for (int j = 2; j <= x / 2; j++) {
                if (isPrime[j] && isPrime[x - j]) {
                    answer++;
                }
            }
            pw.println(answer);
        }
        sc.close();
        pw.close();
    }
}
