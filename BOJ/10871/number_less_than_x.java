import java.io.*;
import java.util.StringTokenizer;

class number_less_than_x {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int len = Integer.parseInt(st1.nextToken());
        int x = Integer.parseInt(st1.nextToken());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        br.close();

        int value;
        for (int i = 0; i<len; i++) {
            value = Integer.parseInt(st2.nextToken());
            if (x > value) {
                bw.write(value+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
}