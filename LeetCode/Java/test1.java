/**
 * test1
 */
public class test1 {

    public static void main(String[] args) {
        String s = "babad";
        int length = s.length();
        String ans = "";
        for(int i = 2; i <= length; i++){
            for(int j = 0; j <= length - i; j++){
                String temp = s.substring(j, j + i);
                int subLength = temp.length();
                int k = 0;
                int sign = 1;
                while(k != subLength / 2){
                    if(temp.charAt(k) != temp.charAt(subLength - k - 1)){
                        sign = 0;
                        break;
                    }
                    k++;
                }
                if(sign == 1 && ans.length() < subLength){
                    ans = temp;
                }
            }
        }
        System.out.println(ans);
    }
}