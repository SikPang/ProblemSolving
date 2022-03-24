import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws Exception {
        Map<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();
        Scanner s = new Scanner(System.in);
		int n = s.nextInt();
        int[] num = new int[n];
        int sum = 0;
        int max = 0;
        int avg = 0;
        int center = 0;
        int lots = 0;
        int range = 0;

        for(int i=0; i<n; i++){
            num[i] = s.nextInt();
            sum+=num[i];
        }
        avg = Math.round((float)sum/n);
        
        Arrays.sort(num);
        center = num[n/2];

        for(int i=0; i<n; i++){
            if(!map.containsKey(num[i]))    // 해당 키가 없으면 새로 추가
                map.put(num[i], 1);
            else
                map.put(num[i], map.get(num[i])+1);
        }

        max = Collections.max(map.values());
        for(Integer i : map.keySet()){      // 최댓값을 가진 모든 값들 list에 추가
            if(map.get(i) == max)
                list.add(i);
        }
        
        if(list.size()>1){
            Collections.sort(list);         // list 정렬
            lots = list.get(1);             // 두번째 값
        }
        else
            lots = list.get(0);

        range = num[n-1] - num[0];

		System.out.println(avg);
        System.out.println(center);
        System.out.println(lots);
        System.out.println(range);
    }
}