import java.io.*;

class take_star2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int num = Integer.parseInt(br.readLine());
        for (int i = 1; i < num+1; i++) {
            bw.write(" ".repeat(num-i)+"*".repeat(i)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}