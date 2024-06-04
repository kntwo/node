#include <stdio.h>  
  
// ����һ������ָ������  
typedef void (*callback_t)(int);  
//typedef int * callback_t �Ա�
// ����һ�������������������һ��������һ���ص�����  
void demo_function(int x, callback_t callback) {  
    printf("The value of x is: %d\n", x);  
    // ���ûص�����  
    (*callback)(x);  
}  
  
// ����һ���ص��������������һ��������ƽ��  
void square(int x) {  
    printf("The square of %d is: %d\n", x, x * x);  
}  
  
int main() {  
    // ����demo_function������������ص�����square  
    demo_function(5, square);  
    return 0;  
}   
