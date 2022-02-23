import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        Stack<Integer> stack = new Stack<>();
        int[] answer = new int[prices.length];

        for (int i = 0; i < prices.length; i++) {
            while(true){
                if(stack.size() == 0 || prices[stack.peek()] <= prices[i]) break;
                
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.push(i);
        }

        while(stack.size()!=0){
            answer[stack.peek()] = prices.length-1 - stack.peek();
            stack.pop();
        }

        return answer;
    }
}