public class removeDuplicates {
    public static boolean[] map = new boolean[26];

    public static void removeDuplicatesFromString(String str, int idx, String newstr) {
        if (idx == str.length()) {
            System.out.println(newstr);
            return;
        }

        char currChar = str.charAt(idx);
        // to check whether at that index the value is true or not which implies the // character is already present or not

        if (map[currChar - 'a']) { // currChar-'a' is index from "present" array eg.for 'b':96 so position of 'b' // in "present" array is 'b'-'a' = 96-95 = 1
                                   
            removeDuplicatesFromString(str, idx + 1, newstr);
        } else {
            newstr += currChar;
            map[currChar - 'a'] = true;
            removeDuplicatesFromString(str, idx + 1, newstr);// add the current character (as it is not repeated till // now) to the returning answer string
                                                             
        }
    }

    public static void main(String[] args) {

        String str = "xmovexallxtoxend";
        String newstr = "";
        removeDuplicatesFromString(str, 0, newstr);
    }
}
