import java.util.HashMap;
import java.util.Map;

public class MapDema {

    static Map<Integer, Integer> count(int[] numbers) {

        Map<Integer, Integer> map = new HashMap<>();
        //遍历
        for (int n : numbers) {
            int c = map.getOrDefault(n, 0);
            map.put(n, c + 1);
            //n 是number；c 是value（次数）
        }
        return map;
    }



    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 2, 3, 4, 3, 5, 4, 6, 7};

        Map<Integer, Integer> map = count(numbers);
        //遍历
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int n = entry.getValue();
            if (n == 2) {
                System.out.println(num);
            }
         }

       }
    }


