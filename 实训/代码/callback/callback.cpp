#include <stdio.h>  
  
// 定义一个函数指针类型  
typedef void (*callback_t)(int);  
//typedef int * callback_t 对比
// 定义一个函数，这个函数接受一个整数和一个回调函数  
void demo_function(int x, callback_t callback) {  
    printf("The value of x is: %d\n", x);  
    // 调用回调函数  
    (*callback)(x);  
}  
  
// 定义一个回调函数，用于输出一个整数的平方  
void square(int x) {  
    printf("The square of %d is: %d\n", x, x * x);  
}  
  
int main() {  
    // 调用demo_function函数，并传入回调函数square  
    demo_function(5, square);  
    return 0;  
}   
