#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
测试集：
    功能测试：
        存在负数节点的情况下：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8 
        多个节点值和目标值相等的情况下：root = [8,4,8,11,null,8,4,7,2,null,null,5,1] , targetSum = 8
        targetSum 为0 的情况下：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 0
        和为targetSum的路径不存在时：root = [5,4,null,11,null,7], targetSum = 9
        targetSum 为负数时: root = [10,5,-3,3,-2,null,11,3,-2,null,-1], targetSum = -3
    Edge case：
        树为空时：root =[], targetSum = 8
        只有左子树：[5,4,null,11,null,7] targetSUm = 9
        只有右子树: [6,null,11,null,7,null,9], targetSum = 9
*/

int getPathSum(TreeNode* node, int tarSum, int sum, unordered_map<long long, int>&sumMap)
{

    if (node == nullptr) {
        return 0;
    }

    int count = 0;
    sum += node->val;

    if (sumMap.count(sum - tarSum)) {
        count += sumMap[sum - tarSum];
    }


    if (sumMap.count(sum)){
        sumMap[sum]++;
    }else {
        sumMap[sum] = 1;
    }


    count += getPathSum(node->left, tarSum, sum, sumMap);
    count += getPathSum(node->right, tarSum, sum, sumMap);

    sumMap[sum]--;

    return count;
}

int pathSum(TreeNode *root, int targetSum)
{
    unordered_map<long long, int> sumMap;
    int sum = 0;
    sumMap[0] = 1;
    
    return getPathSum(root, targetSum, 0, sumMap);
}