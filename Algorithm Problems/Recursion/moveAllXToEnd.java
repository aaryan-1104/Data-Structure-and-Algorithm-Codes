public class moveAllXToEnd {
    public static String addX(int count){
        String xtr="";
        for(int i=1;i<=count;i++){
            xtr+='x';
        }
        return xtr;
    }

    public static String moveX(String str, int idx, int count) {
        if(idx==str.length()){
            return addX(count);
        }
        if(str.charAt(idx)=='x'){
            return moveX(str, idx+1, count+1);
        }
        else{
            String nextstr= moveX(str, idx+1, count);
            return str.charAt(idx)+nextstr;
        }
    }

    public static void main(String[] args) {
        int count=0;
        String str="x move x all x to x end";
        
        System.out.println(moveX(str, 0, count));       
    }
}
