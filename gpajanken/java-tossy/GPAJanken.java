import java.util.Scanner;

public class GPAJanken {
  static final String win_a = "KATO";
  static final String win_b = "SATO";
  static final String draw = "DRAW";

  public static void main(final String[] args) {
    final Scanner sc = new Scanner(System.in);
    final int n = sc.nextInt();

    for(int i=0; i<n; i++) {
      final int a = sc.nextInt();
      final int b = sc.nextInt();

      final String ans;
      if (a > b) ans = win_a;
      else if (a < b) ans = win_b;
      else ans = draw;

      System.out.println(ans);
    }
    sc.close();
  }
}
