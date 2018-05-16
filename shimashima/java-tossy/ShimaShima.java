import java.util.Scanner;

public class ShimaShima {
  public static void main(final String[] args) {
    final Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    for(int i=0; i<n; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      System.out.println((Math.abs(a-b) <= 1) ? "YES" : "NO");
    }

    sc.close();
  }
}
