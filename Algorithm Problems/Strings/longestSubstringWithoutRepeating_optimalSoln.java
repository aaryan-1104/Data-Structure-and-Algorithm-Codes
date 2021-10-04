import java.util.HashSet;

public class longestSubstringWithoutRepeating_optimalSoln {
    
    public static void substr(String str) {
        
        if(str.length()==0){
            return;
        }

        HashSet<Character> s=new HashSet<>();
        int start=0;
        int end=0;
        int max=0;

        while(end<str.length()){
            if(!(s.contains(str.charAt(end)))){
                s.add(str.charAt(end));
                max=Math.max(max,end-start+1);
                end++;
            }
            else{ 
                do{
                    s.remove(str.charAt(start));
                    start++;
                }
                while(str.charAt(start)!=str.charAt(end));  
            }
        }
        System.out.println(max);
    }

    public static void main(String args[]){
        String str = "abcabcbb";
        substr(str);
    }
}
