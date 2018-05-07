import java.io.PrintWriter;
import java.util.Scanner;

public class PairProgramming {
    private static final Scanner sc = new Scanner(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);

    private static void solve() {
        final int n = sc.nextInt();
        int total = 0;
        for (int i = 0; i < n; i++) {
            final int ai = sc.nextInt();
            total += ai;
            pw.println(total % 2);
        }
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
