import java.util.ArrayList;

class Solution {
   public  ArrayList<Integer> solution(int[] arr, int divisor) {
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        
        for(int i=0; i<arr.length; i++) {
        	if(arr[i] % divisor == 0)
        		arrayList.add(arr[i]);
        }
        
        if(arrayList.size() == 0){
        	arrayList.add(-1);
        	return arrayList;
        }
        
        for(int i=0; i<arrayList.size()-1; i++) {
        	 for(int j=0; j<arrayList.size()-1-i; j++) {
        		 if(arrayList.get(j) > arrayList.get(j+1)) {
        			 int temp = arrayList.get(j);
        			 arrayList.set(j, arrayList.get(j+1));
        			 arrayList.set(j+1, temp);
        		 }
        	 }
        }
        
        return arrayList;
    }
}