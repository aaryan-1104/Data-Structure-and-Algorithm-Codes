import java.util.HashSet;

public class uniqueSubsequence {
    public static void subsequences(String str, int idx, String newstr, HashSet<String> set) {

        if (idx == str.length()) {
            if (set.contains(newstr)) {
                return;
            }

            else {
                System.out.println(newstr);
                set.add(newstr);
                return;
            }
        }

        char currChar = str.charAt(idx);

        // if current character wants to to be included in a subsequence
        subsequences(str, idx + 1, newstr + currChar, set);

        // if current character don't wants to to be included in a subsequence
        subsequences(str, idx + 1, newstr, set);
    }

    public static void main(String[] args) {
        String str = "aaa";
        HashSet<String> set = new HashSet<>();
        subsequences(str, 0, "", set);

    }

}
