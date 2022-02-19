import java.util.Arrays;

class Solution {
    public String solution(String s) {
        String[] value = s.split(" ");
        int[] intValue = new int[value.length];
        
        for(int i=0; i<value.length; i++){
            intValue[i] = Integer.parseInt(value[i]);
        }

        Arrays.sort(intValue);
        
        return intValue[0] + " " + intValue[intValue.length-1];
    }
}