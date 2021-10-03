public class firstAndLastOccurence {
    
    public static int first=-1;
    public static int last=-1;

    public static void getIndexFL(String str, char element, int idx){
        if(idx==str.length()){
            return;
        }

        if(str.charAt(idx)==element){
            if(first==-1){
                first=idx;
            }
            else{
                last=idx;
            }
        }
        getIndexFL(str, element, idx+1);
    }
    
    public static void main(String[] args) {
        String str="find first and last Occurence";
        char element='t';
        int idx=0;
        getIndexFL(str, element, idx);
        System.out.println(first+": first Occurence and "+last+": last occurence of "+element);
    }
}
