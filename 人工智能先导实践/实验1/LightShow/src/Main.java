import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        String str = s.nextLine().trim();
        System.out.println(n);
        System.out.println(str);
        //划分并统计两种操作段的个数
        int X_cnt=0,O_cnt=0;
        char last = 'A';
        for(int i=0;i<str.length();i++){
            if(strcmp((str+i),last)){
                if(str+i==X){
                    X_cnt++;
                }else{
                    O_cnt++;
                }
                last = str+i;
            }
        }
        System.out.println(X_cnt);
        System.out.println(O_cnt);
    }
}