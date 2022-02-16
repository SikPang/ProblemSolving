// board[][]
//
// {0,0,0,0,0},
// {0,0,1,0,3},
// {0,2,5,0,1},
// {4,2,4,4,2},
// {3,5,1,3,1}
//
// 4 3 1 1 3 2 4

import java.util.ArrayList;

public class Solution {
	public int solution(int[][] board, int[] moves) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i=0; i<moves.length; i++) {
        	moves[i]--;	// 인덱스로 바꿔줌
        	for(int j=0; j<board.length; j++) { // 행 검사
        		if(board[j][moves[i]] != 0) {
        			list.add(board[j][moves[i]]);
        			board[j][moves[i]] = 0;
        			break;
        		}
        	}
        }
		
        for(int i=0; i<list.size()-1; i++) {
        	if(list.get(i) == list.get(i+1)) {
        		answer+=2;
        		list.remove(i);
        		list.remove(i);
        		if(i>=2)
        			i-=2;
        		else
        			i=-1;
        	}
        }
        
        return answer;
    }
}