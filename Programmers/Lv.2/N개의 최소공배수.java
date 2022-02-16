public class Solution {
	public int solution(int[] arr) {
		int lcm=arr[0];

		for(int i=0; i<arr.length-1; i++){
			int factor = 1;
			int lmcTemp = lcm;
			for(int j=2; j<=lcm; j++){
				System.out.println(j);
				if(lmcTemp%j==0 && arr[i+1]%j==0){
					System.out.println(lmcTemp + " " + arr[i+1] + " " + j);
					lmcTemp /= j;
					arr[i+1] /=j ;
					factor *= j;
					j=1;
				}
			}
			System.out.println(lmcTemp + " " + arr[i+1]);
			lcm=factor*lmcTemp*arr[i+1];
			System.out.println("next: "+ lcm);
		}

        return lcm;
    }
}
