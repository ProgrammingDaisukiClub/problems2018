import java.util.Arrays;
import java.util.Scanner;

public class TwoSquares {
    public static class Point {
        int x, y;

        public Point(final int x, final int y) {
            this.x = x;
            this.y = y;
        }

        public int distSquare(final Point p) {
            int dx = x - p.x;
            int dy = y - p.y;
            return dx * dx + dy * dy;
        }
    }

    private static final Scanner sc = new Scanner(System.in);

    // Return -1 if given 4 points does NOT form a square.
    // If they form a square, return its area.
    private static int getAreaOrNonSquare(final Point list[]) {
        if (list.length != 4) throw new RuntimeException("illegal array length");

        final int lengths[] = new int[6];
        int sz = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                lengths[sz++] = list[i].distSquare(list[j]);
            }
        }
        Arrays.sort(lengths);

        // If given 4 points forms square, then
        // the array is consists of four 'square of one side' and two 'square of one diagonal'
        if (lengths[0] != lengths[1]
                || lengths[1] != lengths[2]
                || lengths[2] != lengths[3]) {
            return -1;
        }

        if (lengths[3] * 2 != lengths[4]) return -1;

        if (lengths[4] != lengths[5]) return -1;

        return lengths[0];
    }

    private static void solve() {
        final Point ps[] = new Point[8];
        for (int i = 0; i < 8; i++) {
            final int x = sc.nextInt();
            final int y = sc.nextInt();
            ps[i] = new Point(x, y);
        }

        // Select 4 points from 8 points
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                for (int k = j + 1; k < 8; k++) {
                    for (int l = k + 1; l < 8; l++) {
                        final Point l1[] = new Point[4];
                        final Point l2[] = new Point[4];
                        int n1 = 0, n2 = 0;
                        for (int x = 0; x < 8; x++) {
                            if (i == x || j == x || k == x || l == x) {
                                l1[n1++] = ps[x];
                            } else {
                                l2[n2++] = ps[x];
                            }
                        }

                        final int a1 = getAreaOrNonSquare(l1);
                        final int a2 = getAreaOrNonSquare(l2);
                        if (a1 > 0 && a2 > 0) {
                            System.out.println(Math.min(a1, a2) + " " + Math.max(a1, a2));
                            return;
                        }
                    }
                }
            }
        }

        throw new RuntimeException("No Two-Squares found!");
    }

    public static void main(final String[] args) {
        final int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            solve();
        }
    }
}
