import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer[]> que = new LinkedList<>();
        Integer[] temp = new Integer[2];
        int totalWeight = 0;
        int totalTruck = 0;
        int sec = 0;
        int i=0;

        while (i<=truck_weights.length-1) {
            sec++;
            if (!que.isEmpty() && sec - que.peek()[1] >= bridge_length) {
                totalWeight -= que.peek()[0];
                totalTruck--;
                que.poll();
            }
            if (totalWeight + truck_weights[i] <= weight && totalTruck + 1 <= bridge_length) {
                temp = new Integer[2];
                temp[0] = truck_weights[i];
                temp[1] = sec;
                que.offer(temp);
                totalWeight += truck_weights[i];
                totalTruck++;
            } else
                i--;
            i++;
        }
        return sec + bridge_length;
    }
}