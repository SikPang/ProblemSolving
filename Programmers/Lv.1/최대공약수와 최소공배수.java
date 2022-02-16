import java.util.ArrayList;

class Solution {
    public long[] solution(long n, long m) {
        long[] answer = {0, 0};
        ArrayList<Long> nValue = new ArrayList<Long>();
        ArrayList<Long> mValue = new ArrayList<Long>();
        ArrayList<Long> tValue = new ArrayList<Long>();
        
        for(long i=1; i<n+1; i++){
            if(n%i==0){
                nValue.add(i);
            }
        }
        
        for(long i=1; i<m+1; i++){
            if(m%i==0){
            	mValue.add(i);
            }
        }
        
        for(int i=0; i<nValue.size(); i++){
           for(int j=0; j<mValue.size(); j++){
                if(nValue.get(i).equals(mValue.get(j))){
                    tValue.add(nValue.get(i));
                }
            } 
        }
        answer[0] = tValue.get(tValue.size()-1);
        answer[1] = n*m/answer[0];
        
        return answer;
    }
}