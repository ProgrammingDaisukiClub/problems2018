import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Fast O(N+M) implementation
public class Zoo {
    private static final Scanner sc = new Scanner(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);
    private static final String RESULT_FIRST = "kawaii";
    private static final String RESULT_SEEN = "moumita";
    private static final String RESULT_UNKNOWN = "siranai";

    private static Set<String> readKnown(){
        final int n = sc.nextInt();
        final Set<String> animals = new HashSet<>();
        for (int i = 0; i < n; i++) {
            final String str = sc.next();
            animals.add(str);
        }
        return animals;
    }

    private static void solve() {
        final Set<String> knownAnimals = readKnown();
        final Set<String> seenAnimals = new HashSet<>();

        final int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            final String currentAnimal = sc.next();
            if (knownAnimals.contains(currentAnimal)) {
                if (!seenAnimals.contains((currentAnimal))) {
                    pw.println(RESULT_FIRST);
                    seenAnimals.add(currentAnimal);
                } else {
                    pw.println(RESULT_SEEN);
                }
            } else {
                pw.println(RESULT_UNKNOWN);
            }
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
