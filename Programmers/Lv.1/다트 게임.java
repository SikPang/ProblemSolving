public class Solution {
	public int solution(String dartResult) {
        int answer = 0;
        int[] score = new int[3];
        String temp ="";
        int sequence = 0;

        for(int i=0; i<dartResult.length(); i++) {
        	if(dartResult.charAt(i)>=48 && dartResult.charAt(i)<=57){
        		temp += dartResult.charAt(i);
        	}
        	else if(dartResult.charAt(i)=='S') {
        		score[sequence] = Integer.parseInt(temp);
        		
        		if(sequence!=2 && dartResult.charAt(i+1)>=48 && dartResult.charAt(i+1)<=57) {
        			temp = "";
            		sequence++;
        		}
        	}
			else if(dartResult.charAt(i)=='D') {
        		score[sequence] = Integer.parseInt(temp);
        		score[sequence] *= score[sequence];
        		
        		if(sequence!=2 && dartResult.charAt(i+1)>=48 && dartResult.charAt(i+1)<=57) {
        			temp = "";
            		sequence++;
        		}
			}
			else if(dartResult.charAt(i)=='T') {
        		score[sequence] = Integer.parseInt(temp);
        		score[sequence] = score[sequence] * score[sequence] * score[sequence];
        		
        		if(sequence!=2 && dartResult.charAt(i+1)>=48 && dartResult.charAt(i+1)<=57) {
        			temp = "";
            		sequence++;
        		}
			}
			else if(dartResult.charAt(i)=='*') {
				if(i==2) {
					score[sequence] *= 2;
				}
				else {
					score[sequence-1] *= 2;
					score[sequence] *= 2;
				}
				temp = "";
        		sequence++;
			}
			else if(dartResult.charAt(i)=='#') {
				score[sequence] *= -1;
				temp = "";
        		sequence++;
			}
        }
        answer = score[0]+score[1]+score[2];
        return answer;
    }
}