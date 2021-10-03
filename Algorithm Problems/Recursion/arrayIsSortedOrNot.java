public class arrayIsSortedOrNot{

    public static boolean checkIfSorted(int arr[], int idx){
        if(idx==arr.length){
            return true;
        }
        if(!checkIfSorted(arr, idx+1)){
            return false;
        }
        return (arr[idx]>arr[idx-1]);
    }
    public static void main(String[] args) {
        int arr[]={0,1,2,3,4,5,6,7,8,9};
        int arr2[]={0,1,2,10,4,5,6,7,9,8};

        System.out.println(checkIfSorted(arr, 1)); 
        System.out.println(checkIfSorted(arr2, 1)); 
    }
}
