import java.util.StringTokenizer;
import java.io.*;

class a_plus_b_minus_5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int a, b;
        while (true) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            if (a == 0 && b ==0) break;
            bw.write(a+b+"\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}