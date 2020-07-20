#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// a customized function
int foo(int n)// n is a parameter => 形参
{
  int i=n;
  while(i>1){
    n *= (n-1);
    i--;
    return n;
  }
}

// a void function to call the function above
void console_output(int input)
{
  printf("\nhello the calc of%d\n is:%i\n", input, foo(input));
}

// conbination of void and pointer 
void getNegetive(int *pt)
{
  *pt = -*pt;
} 

// a struct tryout
typedef struct
{
  int x;
  int y;
  int z;
} position;
// COULD be nested
typedef struct
{
  char fa[20];
  position position;
} father;

int main()
{
  //if || if else || else statement
  {
    if(0||1)
    {
      // printf("hey\n");
    } else if (0&&1) 
    {
      return 0;
    } else
    {
      return 0;
    }
   
    // a little game : guess a number
    {
      srand(time(NULL));
      int randNam = rand();
      randNam %= 6;// create a random number

      // create an input
      // printf("please guess a num between 0 to 5\n");
      int input=0;

      // always check input with while do 
      // while(randNam!=input)
      // {
      //   if(input){
      //     printf("no you are wrong\n");
      //   }
      //   scanf("%i", &input);
      // };

    }

    // single line if statement 
    // if(true) printf("single-line if statement\n"); 只接受一个语句
  }
  
  // alternative ways with && and || operator
  {
            // huge expression => replace if else 
      /*
      => true || x => true
      => false || x => x
      => true && x => x
      => false && x => false
      => (true || y) && x => x
      => true || (y && x) => true
      => expression1 || (condition && expression3) 
        - if condition == ture => excute expression3;
        - if condition == false => excute expression
      */
    // (true&&
    // printf("is true\n")
    // )||
    // (printf("is false\n")
    // );
  }
  
  // switch statement
  {
    int switch_num=1;
    switch (switch_num) 
    {
      case 0:
        break;
      case 1:
        //
        break;
      default:
        break;
    }
  }

  // while loop[&do while]
  // =>easy =>dont no how many loop gonna iterate
    // a sample
  {
    int i=0;
    while(i<10)
    {
      // pass i to the while loop
      int j=0;
      i++;
      while(j<i)
      {
        j++;
        // printf("%i ",j);
        
      }
      // printf("\n");
    }
  }

  // for loop
  // =>easy =>know how many loop gonna iterate

  // Array int myGrades[]=> {ele1, ele2, ele2}
                         // index0 index1 index2
    // **it's index is statically**=> can't change|| but the value can change by `Array[0] = 10;` 
    // find the Array's length=>Array[4]
  {   // multimensional arrays
      int array[2][3] = {
		  {1, 2, 3},
		  {2, 3, 4}
		  };
      array[0][0] = 0;// can change value of an ele
      for (int i = 0;i<2;i++) 
      {
        printf("[");
        for (int j = 0; j < 3; j++)
        {
          printf(" %d ", array[i][j]);
        }
        printf("]\n");
      }
     
     char hey[6] = "hello";// better way: emit 6
     //> [h | e | l | l | o | \0] \0=> NULL:tells the end of the array
     printf("what is your favorate foodd?\n");
     char favFood[51];
     scanf("%50s", favFood);
     printf("you have a good taste || and that is your dinner: \n %s", favFood);
     
     // get array length
     int get_array_length = 0;
     while (favFood[get_array_length] != '\0') 
     {
       get_array_length++;
     }
     printf("\nyour fav food's length:\n%d\n\n", get_array_length);

     // function => 
     //           - don't print , use return
     //           - one use=>do one thing
     
     foo(3);// 3 is arguments => 实参
  }

  // function test
  {
    printf("%d", foo(3));
  }
  
  // void function=>no return test

  console_output(6);
  // pointer
  {
    int slices = 5;
    int *pt = &slices;//`p` is a pointer;use point to a mermory , now a and p cant change the value
    *pt = 22;
    (*pt)++;
    printf("Slices: %d\n", slices);
    printf("Slices pointer: %d\n", *pt);// *pt => get the value of pt

  }

  // pointer[保存16进制内存地址] + void => test
    // 普通值需要&，array不需要&，自动获取到地址
    // (比如把数组地址获取到，作为)实参传入函数，形参使用指针操作的是变量的地址，所以无需返回值
  {
    int f = 88;
    getNegetive(&f);
    printf("%i", f);
  }

  // struct => alike javascript Object
  {
    father myPosition = {"beet",{3,4,5}};
    printf("\n\n\n\n\n\n%s\n and the position is:%d\n", myPosition.fa,myPosition.position.x);
    father *pt = &myPosition;
    printf("what about pointer???:    %s\n",pt->fa);
  }

  return 0;
}
