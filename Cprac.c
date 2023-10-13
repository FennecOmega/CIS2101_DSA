#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 #include ".\Implementations\CursorImplementation.h"

// #include ".\Implementations\LinkedListImplementation.h"

// #include ".\Implementations\ArrayImplementation.h"

 #include ".\Implementations\ComputerWordImplementation.h"


#include ".\TestFiles\StackTest.h"
#include ".\TestFiles\QueueTest.h"
// #include ".\TestFiles\BitVectorTest.h"
#include ".\TestFiles\DictionaryTest.h"

int main(){
  bool isRunning = true;
  int test;

  while(isRunning == true){
  printf("\n1. Stack 2. Queue 3. BitVector (CursorList + Computer Word is 3rd option) 4. Hashing 5. SECRET (end program)\n");
  printf("Enter option: ");
  scanf("%d", &test);
     switch(test){

        case 1:
           StackTest();
        break;
     
        case 2:
           QueueTest();
        break;

        case 3:
           BitVectorTest();
        break;

        case 4:
           DictionaryTest();
        break;

        default:
        printf("Ur motherfucking GAY *dies*");
        isRunning = false;
     }

  }

}