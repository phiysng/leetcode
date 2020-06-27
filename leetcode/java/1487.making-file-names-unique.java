import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public String[] getFolderNames(String[] names) {
        var map = new HashMap<String, Integer>();
        var res = new ArrayList<String>();

        for (var name : names) {
            if (!map.containsKey(name)) {
                map.put(name, 0);
                res.add(name);
            } else {
                int start = map.get(name) + 1;
                while (map.containsKey(name + "(" + start + ")")) {
                    start++;
                }
                map.put(name + "(" + start + ")", 0);
                map.put(name, start);//当前使用的索引
                res.add(name + "(" + start + ")");
            }
        }
        
        return res.toArray(new String[1]);
    }
}
