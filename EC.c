// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define BIT_SET(value, bit) (value = value | (1 << (bit-1)))
#define CLR_BIT(value,bit) (value = value & (~(1 << (bit-1))))
#define TLG_BIT(value,bit) (value = value ^ (1<<(bit-1)))
#define DATA_SIZE   (sizeof(unsigned int)*8)
void tlgBit(int value, int bit);
void clrBit(int value, int bit);
void setBit(int value, int bit);
void decimalToBin(int value);
void stringRev(void);
void charFindOut(void);
void swapNum(int a, int b);
void funPtrExe(void);
void findLNum(void);
void structSize(void);
void findSmallNum(void);
void passByValuRef(int , int *);
void constValue(const int *value);
void constAddr( int *const value);
void constValueAddr( const int *const value);
void mallocFun(void);
void pointer(void);
void EvenOddNum(int);
void revNum(void);
int calculate(int a, int b, int(*funPtr)(int,int));
int funAdd(int a, int b);
int funMull(int a, int b);
int pointerOperation(void);
void LinkList(void);
#define SIZE 5
int stack[SIZE];
int top = -1;
void display(void);
void push(int value);
int pop(void);

int main() {
    // Write C code here
    int a = 10, b = 3;
    //1) BIT_SET(a,b);printf("\n a = %d, b = %d",a,b);
    //   CLR_BIT(a,b);printf("\n a = %d, b = %d",a,b);
    //   TLG_BIT(a,b);printf("\n a = %d, b = %d",a,b);
    //2) setBit(a, b);  clrBit(a,b); tlgBit(a,b);
    //3) decimalToBin(14);
    //4) stringRev();
    //5) charFindOut();
    //6 swapNum(a,b);
    //7 funPtrExe();
    //8 findLNum();
    //9 structSize();
    //10 findSmallNum();
    //11 passByValuRef(a,&b);
    //12 constValue(&a);constAddr(&a);constValueAddr(&a);
    //13 mallocFun();
    //14 pointer();
    //15 EvenOddNum(100);
    //16 revNum();
    //17 printf("\n Value = %d",calculate(5,20,funAdd)); printf("\n Value = %d",calculate(5,20,funMull)); // function pointer
    //18 pointerOperation();
	// 19 LinkList();
	//20 stackInC();
	RotetLeft(0x02,4); RotetRight(0x04,4);

    return 0;
}


void RotetLeft(unsigned int value, unsigned int rotet){
	rotet = rotet % DATA_SIZE;
	value=((value << rotet) | (value >> (DATA_SIZE - rotet)));
	printf("\n 0x%2x",value);
}
void RotetRight(unsigned int value, unsigned int rotet){
	rotet = rotet % DATA_SIZE;
	value = ((value >> rotet) | (value << (DATA_SIZE - rotet)));
	printf("\n 0x%2x",value);
}

void stackInC(void){
   push(10); push(20);
   push(30); push(40);
   push(50);
   display(); pop(); pop();
   printf("\n**********************");
   display();
}
void display(void){
   for(int i =top;i>=0;i--){
      printf("\n %d",stack[i]);
   }
}
void push(int value){
    if(top >=(SIZE-1)){
	   printf("\n stack is full");
	}else{
	     top++;
	   stack[top] = value;
	  
	}
}

int pop(void){
    int value;
   if(top < 0){
      printf("\n stack is empty");
	  return 0;
   }else{
      top--;
      return(stack[top]);
   } 
}

void LinkList(void){
    struct node{
        int data;
        struct node *link;
    };
    
    struct node *linkList = NULL;
    
    linkList = (struct node *)malloc(sizeof(struct node));
    linkList->data = 100;
    linkList->link = NULL;
    printf("\n data = %d",linkList->data);
    printf("\n data = %d",linkList->link);
}

int pointerOperation(void){
     char a = 100,b;
     char *ptr1;
     char **ptr2;
     ptr1 = &a;
     ptr2 = &ptr1;
     printf("\n value = %d",ptr1);
     printf("\n value = %d",ptr1+1);
     printf("\n value = %d",*ptr1);
     printf("\n value = %d",*ptr1+1);
     printf("\n value = %d",**ptr2);
}
int pointerOperation(void){
     int *ptr1 = &1000;
	 
}

int calculate(int a, int b, int (*funPtr)(int,int)){
    return(funPtr(a,b));
}

int funAdd(int a, int b){
    return(a+b);
}
int funMull(int a, int b){
    return(a*b);
}
void revNum(void){
    int num= 1234, rev =0;
    
    while(num !=0){
        rev = rev*10 + num%10;
        num = num/10;
    }printf("rev = %d",rev);
}
void EvenOddNum(int num){
    if(num%2 == 0){
        printf("number is even");
    }else{
        printf("number is odd");
    }
}
void pointer(void){
    // wild pointer
    int *ptr1;
    // null pointer
    int *ptr2 = 0;
    // void pointer
    void *ptr3;
    //dangling pointer
    int *ptr4 = (int*)malloc(sizeof(int));
    free(ptr4);
}
void mallocFun(void){
    int *ptr,*ptr1;
    char *ptr2
    ptr = (int*)malloc(5);
    ptr1 = (int*) calloc(4,sizeof(int));
    // reasign the size
    ptr2 = (char*)realloc(4,sizeof(char))
    free(ptr);
}
void constValueAddr( const int *const value){
    int a=100;
    // *value = 100;
   // value = &a;
    printf("value = %d",*value);
}
void constAddr( int *const value){
    int a=100;
    *value = 100;
   // value = &a;
    printf("value = %d",*value);
}
void constValue(const int *value){
    int a=100;
   // *value = 100;
    value = &a;
    printf("value = %d",*value);
}
void passByValuRef(int a, int *ptr){
    printf("a = %d, b= %d",a,*ptr);
}
void findSmallNum(void){
    char numbers[]={10,20,40,60,10,2,3,88,6};
    char sNum = numbers[0];
    for(int i =0; i<sizeof(numbers);i++){
        if(sNum>numbers[i]){
            sNum=numbers[i];
        }
    }
    printf("small number = %d",sNum);
}
void structSize(void){
    typedef struct{
        int a;
        int b;
        char c;
    }structVer;
     structVer s1;
    printf("\n size = %d",sizeof(s1));
    printf("\n size = %d", (char*)(&s1+1) - ((char*)&s1));
}
void findLNum(void){
    int lNumber =0;
    char array[]={10,20,100,90,80,50,40,30,44};
    for(int i =0; i< sizeof(array);i++){
        if(lNumber<array[i])
        lNumber = array[i];
    }
    printf("lNumber = %d",lNumber);
}
void funPtrExe(void){
    int a = 100, b = 200;
    void (*funtPtr)(int,int);
    funtPtr = swapNum;
    funtPtr(a,b);
}
void swapNum(int a, int b){
    b = a+b;
    a = b - a;
    b = b - a;
    printf("\n a = %d, b = %d",a,b);
}
void charFindOut(void){
    int count=0;
    char string[]="sudam anil vagare";
    for(int i=0;i< sizeof(string);i++){
        if(string[i] == 'a'){
            count++;
        }
    }
    printf("count = %d",count);
}
void stringRev(void){
    char string[] ="sudam anil vagare";
    int length = sizeof(string)-1;
    int i=0; 
    char tempVer;
    while(length>i){
        tempVer = string[i];
        string[i] = string[length];
        string[length] = tempVer;
        i++; 
        length--;
    }
    for(i=0;i<sizeof(string);i++){
    printf("%c",string[i]);
    }
}

void decimalToBin(int value){
    int array[16],cntOne=0,cntZero=0,i=0;
    while(value>0){
        array[i] = value % 2;
        value = value>>1;
        i++;
    }
    for(int j =(i-1);j>=0;j--){
        printf("%d",array[j]);
        if(array[j]==1){
            cntOne++;
        }else{
            cntZero++;
        }
    }
}
void tlgBit(int value, int bit){
    value = value ^ (1<< (bit-1));
    printf("\n value = %d",value);
}
void clrBit(int value, int bit){
    value = value & (~(1<<(bit-1)));
    printf("\n value = %d", value);
}
void setBit(int value, int bit){
    value = value | (1<<(bit-1));
    printf("\n value =%d",value);
}


typedef union {
	unsigned char bit0 :1;
	unsigned char portA;
}POART;

POART A;
