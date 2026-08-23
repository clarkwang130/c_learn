#include <iostream>
using std::cout;


float sum_elements(float a[], unsigned length){
    int i;
    float result = 0;

    for(i = 0; i<length; i++)
        result += a[i];
    return result;
}

void test(){
    float x[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
    float result = sum_elements(x, 5);
    cout << result;

}

int main() {
  test();
  
  printf("Hello\c");
  return 0;
}   



