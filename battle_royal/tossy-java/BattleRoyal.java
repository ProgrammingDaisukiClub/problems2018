import java.util.Scanner;
import java.util.stream.IntStream;

public class BattleRoyal {
    private static final Scanner sc = new Scanner(System.in);
    private static final int N = 100;

    private static void solve() {
        final int k[] = new int[N];
        for (int i = 0; i < N; i++) {
            k[i] = sc.nextInt();
        }
        int total = IntStream.of(k).sum();
        System.out.println(100 - total);
    }

    public static void main(final String[] args) {
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            solve();
        }
    }
}
