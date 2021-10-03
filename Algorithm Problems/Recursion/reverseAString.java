public class reverseAString {

    public static String reverseString(String str) {
        if(str.length()==1){
            return str;
        }

        char currchar=str.charAt(0);
        String nextstring=reverseString(str.substring(1));
        return nextstring+currchar;
    }

    public static void main(String args[]) {
     String str="reverse the string";
     System.out.println(reverseString(str));   
    }
}
