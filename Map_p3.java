import java.util.*;

public class Map_p3 {
    //宝石和石头
    public int numJewelsInStones(String J, String S){
        int count=0;
        Set<Character> j=new HashSet<>();
        for(char c:J.toCharArray()){
            j.add(c);
        }
        for(char c:S.toCharArray()) {
            if (j.contains(c)) {
                count++;
            }
        }
return count;
    }
    //统计出现次数最多的单词
    public List<String> topKFrequent(String[] words, int k){
        Map<String,Integer>mapWord=new HashMap<>();
        for(String s:words){
            int c=mapWord.getOrDefault(s,0);
            mapWord.put(s,c+1);
        }
        return mapWord;
    }

}
