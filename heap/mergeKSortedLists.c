/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* ListNode;
// 堆下标从0开始，根节点和孩子节点的索引
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

// 维护最小堆的性质
void min_heapify(ListNode heap[], int length, int index){
    int l = LEFT(index); // 左孩子对应下标
    int r = RIGHT(index);

    int smallest = 0; // 暂存 根节点及左、右孩子最大值的索引
    //printf("%d\n", heap[index]->val);
    //printf("%d\n", heap[l]->val);
    
    if(l <= length-1 && heap[l]->val < heap[index]->val) smallest = l;
    else smallest = index;
    if(r <= length - 1 && heap[r]->val < heap[smallest]->val) smallest = r;

    if(smallest != index){ // 不满足最大堆的性质时，
        //int tmp = heap[smallest]->val; // 交换
        //heap[smallest]->val = heap[index]->val;
        //heap[index]->val = tmp;
        ListNode tmp = heap[smallest];
        heap[smallest] = heap[index];
        heap[index] = tmp;
        min_heapify(heap, length, smallest); // 递归地往下进行
    }
}
// 建堆
void buildHeap(ListNode heap[], int length){
    int start = (length % 2 == 0) ? (length/2) : ((length-1)/2);
    for(int i = start - 1; i >= 0; i--)
        min_heapify(heap, length, i);

}

void delete(ListNode heap[], int listsSize){
    if(listsSize < 1) return;
    heap[0] = heap[listsSize-1];
    listsSize = listsSize - 1;
    min_heapify(heap, listsSize, 0);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(lists==NULL || listsSize <1) return NULL;
    ListNode res = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode tail = res;
    ListNode tmp[listsSize];
    int t  = 0;
    for(int i = 0; i<listsSize; i++)
    {
        if(lists[i]!=NULL) 
            tmp[t++] = lists[i];
    }
    listsSize = t;
    printf("%d\n", t);
    buildHeap(tmp, listsSize);
    // 为空时， 应该删除此节点
    for(int i = 0; i<listsSize; i++) printf("%d\n", tmp[i]->val);

    while(tmp[0]!=NULL && listsSize>0){
        printf("now %d\n", tmp[0]->val);
        tail->next = tmp[0];
        tail = tmp[0];
        if(tmp[0]->next==NULL) { 
        delete(tmp, listsSize); 
        listsSize--;
        }
        else{
            tmp[0] = tmp[0]->next;  
            min_heapify(tmp, listsSize, 0); 
        }
    }
        tail->next = NULL;
    return res->next;
}