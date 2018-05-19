import java.io.PrintWriter;
import java.util.Scanner;

public class BattleRoyal {
    private static final Scanner sc = new Scanner(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);
    private static final int N = 100;

    private static void solve() {
        int total = 0;
        for (int i = 0; i < N; i++) {
            total += sc.nextInt();
        }
        pw.println(100 - total);
    }

    public static void main(final String[] args) {
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            solve();
        }
        sc.close();
        pw.close();
    }
}
