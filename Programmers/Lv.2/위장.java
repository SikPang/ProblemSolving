import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, ArrayList<String>> map = new HashMap<>();
        ArrayList<String> list;
        int answer = 1;
        int cnt = 0;

        for (int i = 0; i < clothes.length; i++) {
            list = new ArrayList<>();
            if (map.get(clothes[i][1]) != null)
                list = map.get(clothes[i][1]);
            list.add(clothes[i][0]);
            map.put(clothes[i][1], list);
        }

        for (String key : map.keySet()) {
            if (cnt == 0)
                answer = map.get(key).size() + 1;
            else
                answer *= map.get(key).size() + 1;
            cnt++;
        }

        return answer - 1;
    }
}