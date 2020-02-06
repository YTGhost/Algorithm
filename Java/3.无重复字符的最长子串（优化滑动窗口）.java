class Solution {
    public int lengthOfLongestSubstring(String s) {
        // 滑动窗口优化
        Map<Character, Integer> map = new HashMap<Character, Integer>();    // 设置HashMap
        int max = 0;
        int length = s.length();
        for(int i = 0, j = 0; j < length; j++){
            if(map.containsKey(s.charAt(j))){   // 在表中寻找是否有重复的字符
                i = Math.max(map.get(s.charAt(j)) + 1,i);   // 如果字符在[i, j)之间，就更新i
            }
            max = Math.max(max, j - i + 1);     // 计算当前子列长度是否大于最长大小
            map.put(s.charAt(j), j);            // put新的键值对
        }
        return max;
    }
}