public class Solution {
    
    private Map<Integer, ArrayList<Integer>> maps = new TreeMap<Integer, ArrayList<Integer>>();
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        zigzag(root, 0);
        return new ArrayList<List<Integer>>(maps.values());
    }

     public void zigzag(TreeNode node, int level){
        if(node == null){
            return;
        }
        
        if(maps.containsKey(level) == false){
            maps.put(level, new ArrayList<Integer>());
        }