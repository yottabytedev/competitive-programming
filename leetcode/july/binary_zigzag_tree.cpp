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
        if(level % 2 == 1){
                maps.get(level).add(0, node.val);
            }else{
                maps.get(level).add(node.val);
            }
            
            zigzag(node.left, level + 1);
            zigzag(node.right, level + 1);
        }
}