import java.util.Scanner;

public class Main{
    static final int maxN = 5000000;
    static boolean[] isPrime = new boolean[maxN + 1];
    static Scanner sc = new Scanner(System.in);

    private static void uN_prime(){
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;
        isPrime[3] = true;
    
        for(int i = 4; i < maxN + 1; ++i){
            if(i % 6 == 1 || i % 6 == 5){
                isPrime[i] = true;
            }else{
                isPrime[i] = false;
            }
        }
    
        for(int i = 5; i < maxN + 1; ++i){
            if(isPrime[i]){
                for(int k = 2; k <  maxN/i + 1; ++k){
                    isPrime[i * k] = false;
                }
            }
        }
    }

    public static void main(String[] args) {
        uN_prime();
    
        int T;
        T = Integer.parseInt(sc.next());
        
        int E;
        int ans = 0;
        for(int t = 0; t < T; ++t){
            ans = 0;
            E = Integer.parseInt(sc.next());

            for(int p = 2; p < E/2 + 1; ++p){
                if(isPrime[p] && isPrime[E - p]){
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}