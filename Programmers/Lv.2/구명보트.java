import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        ArrayList<Integer> list = new ArrayList<>();
        int answer = 0;

        Arrays.sort(people);
        for (int k = 0; k < people.length; k++)
            list.add(people[k]);

        while (true) {
            if (list.isEmpty()) break;

            if (list.size() > 1) {
                if (list.get(0) + list.get(list.size() - 1) <= limit)
                    list.remove(0);
                list.remove(list.size() - 1);
            }
            else
                list.remove(0);
            answer++;
        }

        return answer;
    }
}