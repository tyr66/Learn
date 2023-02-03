#include <iostream>
#include <set>
using namespace std;

/*
    思路1：二分查找的思想，关键在于如何保存预定的区间。使其动态的保持有序。
    STL 中 set 内部的容器是一颗红黑树，因此可以在插入过程中动态的保持有序
    并且能进行自我调节保持树的平衡，使每一次查找的时间复杂度为O(lgn)

    时间复杂度：O(nlogn) 每一次查找的时间复杂度为O(logn) ，红黑树
    每一次插入元素后都有可能调整树，每一次调整的时间复杂度为 O(logn)

    空间复杂度: O(n) 树种最多存在n个节点
*/

/*
    TODO 思路2: 线段树
*/

class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        
        auto it = books.lower_bound({end, 0});

        if (it == books.begin() || (--it)->second <= start) {
            books.emplace(start, end);
            return true;
        }
        return false;
    }

private:
    set<pair<int, int>> books;
};

int main()
{
    pair<int, int> ip;
    pair<int, int> ip2;

    if (ip > ip2) {

    }
}