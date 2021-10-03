public class towerOfHanoi {

    public static void towerofHanoi(int n, String src,String helper,String dstn){
        
        //base case
        if(n==1){
            System.out.println("Transfer disk "+n+" from "+src+" to "+dstn);
            return;
        }
        //move n-1 disks from "source" to "helper" using destination as helper
        towerofHanoi(n-1, src, dstn, helper);

        //move nth disk from sorce to destination
        System.out.println("Transfer disk "+n+" from "+src+" to "+dstn);

        //move n-1 disks from "helper" to "destination" using source as helper
        towerofHanoi(n-1, helper, src, dstn);

    }
    public static void main(String args[]) {
        int n = 3;
        towerofHanoi(n, "A", "B", "C");
    }
}