// 堆下标从0开始，根节点和孩子节点的索引
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)



// 维护最大堆的性质， A[parent(i)] >= A[i]
void max_heapify(int heap[], int length, int index){
    int l = LEFT(index); // 左孩子对应下标
    int r = RIGHT(index);
    int largest = 0; // 暂存 根节点及左、右孩子最大值的索引
    if(l <= length-1 && heap[l] > heap[index]) largest = l;
    else largest = index;
    if(r <= length - 1 && heap[r] > heap[largest]) largest = r;

    if(largest != index){ // 不满足最大堆的性质时，
        int tmp = heap[largest]; // 交换
        heap[largest] = heap[index];
        heap[index] = tmp;
        max_heapify(heap, length, largest); // 递归地往下进行
    }
}
// 建堆
void buildHeap(int heap[], int length){
    int start = (length % 2 == 0) ? (length/2) : ((length-1)/2);
    for(int i = start - 1; i >= 0; i--)
        max_heapify(heap, length, i);

}

void delete(int heap[], int length){
    heap[0] = heap[length-1];
    length = length - 1;
    max_heapify(heap, length, 0);
}

int findKthLargest(int* nums, int numsSize, int k) {
    if(numsSize < 1 || k>numsSize) return 0;
    int flag = 1;
    buildHeap(nums, numsSize);
    while(flag < k){
        printf("%d\n", nums[0]);
        delete(nums, numsSize);
        numsSize--;
        flag++;
    }
    return nums[0]; 
}