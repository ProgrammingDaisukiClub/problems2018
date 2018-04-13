import java.util.Scanner;

// Naive O(NM) implementation
public class Zoo {
    private static final Scanner sc = new Scanner(System.in);
    private static final String RESULT_FIRST = "kawaii";
    private static final String RESULT_SEEN = "moumita";
    private static final String RESULT_UNKNOWN = "siranai";

    // Return true if str appears in arr[0:n)
    // Otherwise, return false
    private static boolean checkAppearance(final String arr[], final int n, final String str) {
        for(int i=0; i<n; i++) {
            if(arr[i].equals(str)) return true;
        }
        return false;
    }

    private static void solve() {
        final int n = sc.nextInt();
        String knownAnimals[] = new String[n];
        for (int i=0; i<n; i++) {
            knownAnimals[i] = sc.next();
        }

        final int m = sc.nextInt();
        String checkAnimals[] = new String[m];
        for (int i=0; i<m; i++) {
            checkAnimals[i] = sc.next();

            if(checkAppearance(knownAnimals, n, checkAnimals[i])) {
                // known
                if(checkAppearance(checkAnimals, i, checkAnimals[i])) {
                    System.out.println(RESULT_SEEN);
                } else {
                    System.out.println(RESULT_FIRST);
                }
            } else {
                // unknown
                System.out.println(RESULT_UNKNOWN);
            }
        }
    }

    public static void main(final String[] args) {
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            solve();
        }
    }
}
