class Solution {
    public int solution(int n) {
        int cnt = 0;
        int cnt2 = 0;
        String string = Integer.toBinaryString(n);
        
        for(int i=0; i<string.length(); i++){
            if(string.charAt(i) == '1')
                cnt++;
        }

        int i=1;
        while(true){
            string = Integer.toBinaryString(n+i);
            cnt2=0;
            for(int j=0; j<string.length(); j++){
                if(string.charAt(j) == '1')
                    cnt2++;
            }
            if(cnt2==cnt) return n+i;
            i++;
        }
    }
}