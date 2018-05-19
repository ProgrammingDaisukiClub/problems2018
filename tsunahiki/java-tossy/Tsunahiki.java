import java.io.PrintWriter;
import java.util.Scanner;

// O(N^2) solution
public class Tsunahiki {
    private static final Scanner sc = new Scanner(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);
    private static final int MAX_N = 100;
    private static final int a[] = new int[MAX_N];
    private static final int b[] = new int[MAX_N];

    private static boolean check(final int n, final int ans) {
        // try to win `ans` times
        // we only need to check following inequality
        // b[0] < a[n-ans]
        // b[1] < a[n-ans+1]
        // ...
        // b[ans-1] < a[n-1]

        for (int i = 0; i < ans; i++) {
            if (b[i] >= a[n - ans + i]) return false;
        }

        return true;
    }

    private static void solve() {
        final int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }

        for (int ans = n; ans >= 0; ans--) {
            if (check(n, ans)) {
                pw.println(ans);
                return;
            }
        }

        throw new RuntimeException();
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
