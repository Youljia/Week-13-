# 	Week-13-

## AVL树和红黑树

### AVL树

* 是一个平衡二叉树--》对于任意一个节点，平衡因子（左子树高度-右子树高度）的绝对值都不能大于1

* AVL树保证了树的平衡，不往左右偏移

* AVL树是基于BST树（key,value）实现的，既有BST的性质，也有AVL的性质

  * 在add和remove的时候，可能会破坏树的平衡，所以需要进行一下维护一下平衡

    ```c++
    //维护节点的height
    	ret->height = 1 + max(get_height(ret->left), get_height(ret->right));
    	//计算一下平衡因子，看是否需要维持自平衡
    	int balanced_factor = get_balanced_factor(ret);
    	//LL型
    	if (balanced_factor > 1 && get_balanced_factor(ret->left) >= 0)
    		return right_rotate(ret);
    	//RR型
    	if (balanced_factor < -1 && get_balanced_factor(ret->left) <= 0)
    		return left_rotate(ret);
    	//LR型 
    	if (balanced_factor > 1 && get_balanced_factor(ret->left) < 0) {
    		ret->left = left_rotate(ret->left);
    		return right_rotate(ret);
    	}
    	//RL型
    	if (balanced_factor < -1 && get_balanced_factor(ret->left) > 0) {
    		ret->right = right_rotate(ret->right);
    		return left_rotate(ret);
    	}
    ```

    

  * 如何维护自平衡

    * 右旋转

      * 当树向左偏移的时候，y的平衡因子>1

        ```c++
        	Node* x = y->left;
        	Node* T3 = x->right;
        	//倒转
        	x->right = y;
        	y->left = T3;
        	//维护height
        	y->height = 1 + max(get_height(y->left), get_height(y->right));
        	x->height = 1 + max(get_height(x->left), get_height(x->right));
        	return x;
        ```

    * 左旋转

      * 当树向右偏移的时候，y的平衡因子<-1

        ```c++
        	Node* x = y->right;
        	Node* T3 = x->left;
        	x->left = y;
        	y->right = T3;
        	y->height = 1 + max(get_height(y->left), get_height(y->right));
        	x->height = 1 + max(get_height(x->left), get_height(x->right));
        	return x;
        ```


* 基于AVL树实现集合（Set）和映射（Map）
  * 由于AVL树是有着key和value的，所以Map可以直接赋用
  * 对于Set可以忽略value，只使用key，限制用户接口就好了

### 红黑树

* 2-3树
  * 性质
    * 满足二分搜索树的基本性质
    * 节点可以存放一个（二节点）或者两个元素（三节点）
  * 特点
    * 独特的添加操作，让2-3树是一个绝对平衡的树（绝对平衡--任何节点的左右子树高度差都为0）
  * 如何维持特点的？
    * 添加操作的原则 --》 不在空的地方添加一个新的元素，而是与经历的最后一个叶子节点进行融合
    * 融合之后可能是一个二节点不做处理，可能是个三节点，进行拆解
* 红黑树的特点
  * 红黑树等价于2-3树，只不过红黑树每个节点只存储一个元素。
  * 红黑树的每一个节点不是黑色就是红色
  * 叶子节点（最后的空节点）都是黑色
  * 根节点一定是黑色
  * 红色节点的孩子节点一定是黑色
  * 从任意一个节点到叶子节点所经历的黑色节点个数相同--》黑平衡
* 红黑树的辅助操作
  * 颜色翻转
  * 左旋转
  * 右旋转
  * 所有的可能性都在一条链子上的
* 二分搜索树，AVL树以及红黑树的性能比较
  * 当数据非常无序的时候 --》二分搜索树
  * 但数据有序且执行查询操作比较多 --》AVL树
  * 执行增加和删除操作比较多，且统计性能更加优异--》红黑树

## 哈希表和SQRT分解

### 哈希表

* 哈希表的查找算法的复杂度为O（1）
* 如何实现？？
  * 通过哈希函数，将键转化为索引值，就可以直接通过数组索引来访问值了。
  * 例如--》将26个字母减去'a'即可得到26个索引，且互相不冲突，则“字母-‘a'”就是哈希函数

* 实现哈希表的难点
  * 哈希函数（将键和索引连接起来的函数）是非常难找到的
  * 存在哈希冲突，即通过哈希函数转换的时候不同的键转换成了同一个索引
