/* 交换两个数 
* 函数调用实例：swap(int &x, int &y)
*/
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}