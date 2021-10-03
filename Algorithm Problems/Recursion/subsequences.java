public class subsequences {
    public static void subsequence(String str, int idx, String newstr) {

        if (idx == str.length()) {
            System.out.println(newstr);
            return;
        }

        char currChar = str.charAt(idx);

        // if current character wants to to be included in a subsequence
        subsequence(str, idx + 1, newstr + currChar);
        
        // if current character don't wants to to be included in a subsequence
        subsequence(str, idx + 1, newstr);
    }

    public static void main(String[] args) {
        String str = "abc";
        subsequence(str, 0, "");

    }

}
