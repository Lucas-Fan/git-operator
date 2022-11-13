/*
 * @Author: fanzy3 fanzy3@asiainfo.com
 * @Date: 2022-11-13 22:08:04
 * @LastEditors: fanzy3 fanzy3@asiainfo.com
 * @LastEditTime: 2022-11-13 22:13:13
 * @FilePath: /git-operator/function.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 堆排序
void heapSort()
{
   int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
   int len = (int)sizeof(arr) / sizeof(*arr);
   for (int i = len; i > 1; i--)
      heap_Sort(arr, i); //建立堆 每次规模-1

   for (int i = 0; i < len; i++)
      printf("%d ", arr[i]);
   return 0;
}

//构造一个大顶堆并将最大值换至最后一位
void heap_Sort(int arr[], int len)
{
   int dad = len / 2 - 1; //最后一个父节点
   int son = 2 * dad + 1; //该父节点下的首个子节点
   while (dad >= 0)
   {
      //判断是否有两个子节点若有则在其中寻找最大子节点
      if (son + 1 <= len - 1 && arr[son] < arr[son + 1])
         son++;
      if (arr[dad] < arr[son]) //若父节点小于子节点则交换位置
         swap(&arr[dad], &arr[son]);
      dad--;             //回退到上一个父节点
      son = 2 * dad + 1; //上一个父节点的首个子节点
   }
   swap(&arr[0], &arr[len - 1]);
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

// 快排
void quickSort()
{
   int arr[10] = {11, 7, 9, 3, 4, 6, 2, 8, 5, 3};
   quick_sort(arr, 0, 9);
   for (int i = 0; i < 10; i++)
      printf("%d\t", arr[i]);
}

int partition(int arr[], int start, int end)
{
   int temp = arr[start];
   int li = start, ri = end;
   while (li < ri)
   {
      while (li < ri && arr[ri] > temp)
         ri--;
      if (li < ri)
      {
         arr[li] = arr[ri];
         li++;
      }
      while (li < ri && arr[li] < temp)
         li++;
      if (li < ri)
      {
         arr[ri] = arr[li];
         ri--;
      }
   }
   arr[li] = temp;
   return li;
}

void quick_sort(int arr[], int start, int end)
{
   if (start < end)
   {
      int index = partition(arr, start, end);
      quick_sort(arr, start, index - 1);
      quick_sort(arr, index + 1, end);
   }
}
