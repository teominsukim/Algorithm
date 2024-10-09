import java.util.*;
import java.io.*;

// 크루스칼 알고리즘
// 경로 압축 알고리즘
// 부모 노드가 같은것과 만나서는 안된다.

public class Main {
    static int[] parent;
    public static void main(String[] args) throws IOException{
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        // parent 를 초기화한다 - 크루스칼 알고리즘을 위해서
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        // 연결 상황을 입력받는다
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            if (find(u) == find(v)) {
                System.out.println(i+1);
                return;
            }
            int a = find(u) < find(v) ? u : v;
            int b = find(u) > find(v) ? u : v;
            parent[find(b)] = find(a);
        }
        System.out.println(0);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    public static int find(int a){
        if (parent[a] == a)
            return a;
        else
            return find(parent[a]);
    }
}