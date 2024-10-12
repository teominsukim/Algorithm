import java.util.Scanner;

public class Main {
    public static final int MAX = 999999;
    static int[][] graph;
    static int N;
    static int M;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();;
        graph = new int[N+1][N+1];
        // 초기화 하는 코드
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                graph[i][j] = MAX;
                if(i == j){
                    graph[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <= M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        floyd();
        printResult();
    }

    public static void floyd() {
        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    graph[i][j] = Math.min(graph[i][k]+graph[k][j],graph[i][j]);
                }
            }
        }
    }

    public static void printResult(){
        int min = MAX;
        int result = 0;
        for(int i = 1; i <= N; i++) {
            int temp = 0;
            for(int j = 1; j <= N; j++){
                temp += graph[i][j];
            }
            if(temp < min){
                min = temp;
                result = i;
            }
        }
        System.out.println(result);
    }

}