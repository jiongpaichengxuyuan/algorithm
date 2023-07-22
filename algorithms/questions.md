* binary_tree    
    * 5.Binary_tree_level_order_traversal.cc
        * 107层序遍历2 [力扣题目链接](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)
        * 104二叉树最大深度 [力扣题目链接](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)
        * 111二叉树最小深度 [力扣题目链接](https://leetcode.cn/problems/minimum-depth-of-binary-tree/submissions/)（需要注意）

* back_tracking
    * 2.combine.cc
        * 77组合
        * 216组合
    * 5.phone_number_map_combine.cc
        * 17电话号码映射
    * 7.combine_sum.cc
        * 39组合相加
        * 40组合相加，关键在于排序，然后剪枝条件为在循环中重复的数字会造成结果的重复，continue即可
    * 9.split_palindrome_string.cc
        * 131分割回文串，思路：首先一个字符串是一个整体，从第0个位置开始分割，剪枝条件为判断当前分割出来的字串是否是回文串，是则push，否则continue，并且第一轮循环i=0,index=0，因此相当于将字符串分割成了一个一个的字符，第二轮会将头两个字符组成字符串，剩下的仍然是单个字符。递归的终止条件是index>=s.size()
    * 机器人的运动范围：easy
    * 10.recovery_ip_address.cc
        * 94复原IP地址，还是挺简单的，每一次都判断子串是否符合条件即可
    * 11.subsets.cc
        * 78子集，easy
        * 90子集2，需要排序＋在同一层排除重复的
        * 491找递增子序列，注意子序列是可以不连着的，同样需要注意在同一层排除重复，可以直接遍历，也可以利用hash

* dynamic_planning
    * 4.climb_stairs.cc
        * 764爬楼梯的最小花费
    * 7.different_path.cc
        * 63有障碍的网格机器人走到终点
    * 9.different_BST
        * 96n个不同节点二叉搜索树的结构数量、
    * 12.01_backpack_problem.cc
        * 01完全背包问题
    * 13.divide_equal_sum_subsets.cc
        * 416分割等和子集，就是01背包问题，只不过value就是weight本身
    * 16.find_target_sum_ways
        * 494找到目标和的方法，数组里的数即可以加也可以减，那么就涉及到一个公式leaft+right=sum，left-right=target，so left = (sum + target) / 2，因此找到目标和为target的方法数即可