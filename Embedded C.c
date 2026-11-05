// 1. Circuler buffer
#include<stdio.h>

#define SIZE 5
typedef struct{
	int buffer[SIZE];
	int head;
	int tail;
	int count;
}CirculerBuffer;

void BufferInit(CirculerBuffer *temp){
	temp->head=0;
	temp->tail=0;
	temp->count=0;
}

int isBufferFull(CirculerBuffer *temp){
     return(temp->count == SIZE);
}

int isBufferEmpty(CirculerBuffer *temp){
	return(temp->count == 0);
}

void addinQueue(CirculerBuffer *temp, int value){
	if(!isBufferFull(temp)){
		temp->buffer[temp->head] = value;
		temp->head = (temp->head + 1) % SIZE;
		temp->count++;
	}else{
		printf("Buffer is full \n");
	}
}

int removeQueueValue(CirculerBuffer *temp){
	int value;
	if(!isBufferEmpty(temp)){
		value = temp->buffer[temp->tail];
		temp->tail = (temp->tail + 1) % SIZE;
		temp->count --;
		return value;
	}else{
		printf("Buffer is Empty\n");
	}
}

void showQueueValue(CirculerBuffer *temp){
	int i;
	int index = temp->tail;
	for(i=0;i<temp->count;i++){
		printf("%d \t ",temp->buffer[index]);
		index = (index+1)%SIZE;
	}
}
int main(){
	CirculerBuffer stCirculerBuffer;
    BufferInit(&stCirculerBuffer);
    addinQueue(&stCirculerBuffer,100);
	addinQueue(&stCirculerBuffer,200);
	addinQueue(&stCirculerBuffer,300);
	addinQueue(&stCirculerBuffer,400);
	addinQueue(&stCirculerBuffer,500);
	addinQueue(&stCirculerBuffer,600);
	addinQueue(&stCirculerBuffer,700);
	
	showQueueValue(&stCirculerBuffer);
	
    removeQueueValue(&stCirculerBuffer);
	
	showQueueValue(&stCirculerBuffer);
}

// Program 2. MCU Stack Program
#include<stdio.h>
#define SIZE 5

typedef struct{
	int stack[SIZE];
	int count;
}McuStack;


void stackInit(McuStack *temp){
	temp->count = -1;
}

int isStackFull(McuStack *temp){
	return(temp->count >= SIZE-1);
}

int isStackEmpty(McuStack *temp){
	return(temp->count < 0);
}

void push(McuStack *temp, int value){
	
	if(!isStackFull(temp)){
		temp->count++;
		temp->stack[temp->count] = value;
	}else{
		printf("Stack is full \n");
	}
}

void pop(McuStack *temp){
	if(!isStackEmpty(temp)){
		temp->stack[temp->count];
		temp->count--;
	}else{
		printf("Stack is Empty \n");
	}
}

void display(McuStack *temp){
	int i;
	
	for(i=0;i<=temp->count;i++){
	    printf("%d \t ",temp->stack[i]);
	}
}

int main(void){
	McuStack stMcuStack;
	stackInit(&stMcuStack);
	pop(&stMcuStack);
	push(&stMcuStack,10);
	push(&stMcuStack,20);
	push(&stMcuStack,30);
	push(&stMcuStack,40);
	push(&stMcuStack,50);
	push(&stMcuStack,60);
	display(&stMcuStack);
	pop(&stMcuStack);
	printf("\n \n");
	display(&stMcuStack);
}


// Program 3: Find the value from array

#include<stdio.h>

int findArrayValue(int *array, int size, int value){
	int i;
	int index =-1;
	for(i=0;i<size;i++){
		if(array[i] == value){
			return i;
		}else{
			index = -1;
		}		
	}
	return index;
}

int main(void){
	int array[]={10,20,30,40,50,60,70};
	int index;
	index =findArrayValue(array,sizeof(array)/sizeof(int),50);
	printf("Array index = %d",index);
}

// Program 4: Find the Missing Number from Array
#include<stdio.h>

int findMissingNum(int *array, int size){
	int sum=0;
	int sum1=0;
	int i;
	for(i=0; i<size;i++){
		sum +=array[i];
	}
	size = size+1;
	
	sum1 = size*(size+1)/2;
	
	return(sum1-sum);
}

// Program 5: Find Missing Number
#include<stdio.h>

void findMissingNum(int *array, size){
	int sum =0;
	int sum1=0;
	int i;
	
	for(i=0;i<size;i++){
		sum +=array[i];
	}
	size = size+1;
	
	sum1=size*(size+1)/2;
	
	printf("Missing Number = %d",sum1-sum);
	
	
}

int main(void){
	int array[]={1,2,3,4,5,6,7,8,10};
	int missingNum;
	
	missingNum = findMissingNum(array,sizeof(array)/sizeof(int));
	printf("Missing Number = %d",missingNum);
}

// Program 5: Revers the array
#include<stdio.h>

void reversArray(char *array, int size){
	char temp;
	int i=0;
	int sizeTemp = size;
	while(i<size){
		temp = array[i];
		array[i] = array[size];
		array[size] = temp;
		i++;
		size--;
	}
	for(i=0;i<=sizeTemp;i++){
		printf("%c",array[i]);
	}
}

int main(void){
	char array[]="ABCDEFGHIJK";
	reversArray(array,sizeof(array)-2);
}


// Program 6: Revers the Number
#include<stdio.h>

void revNumber(int num){
	int rev = 0;     
	printf("Num = %d \n",num);
	while(num > 0){
		rev = rev * 10 + num % 10;
		num = num/10;
	}
	printf("Rev = %d \n",rev);
}

int main(void){
	revNumber(54321);	
}
while(num>0){
	array[i] =(num&1);
	i++;
	num= num>>1;
}
for(j=i;j>0;j--)
// Program 7: Decimal to bin Conversion
#include<stdio.h>

void decimalToBin(unsigned int num){
	int array[32]={0};
	int i = 0;
	int j = 0;
	while(num > 0){
		if(num % 2){
			array[i] = 1;
		}else{
			array[i] = 0;
		}
		num = num >> 1;
		i++;
	}
	
	for(j=i;j>=0;j--){
		printf("%d",array[j]);
	}
}

int main(void){
	decimalToBin(0x4521);
}

// Program 8: Circuler bit shift
#include<stdio.h>

void circulerLeftShift(unsigned int value,char bit){
	value = (value << bit) | (value >> (32-bit));
	printf("Left Shift = %d\n",value);
}

void circulerRightShift(unsigned int value,char bit){
	value = (value >> bit)|(value <<(32-bit));
	printf("Right Shift = %d\n",value);
}

int main(void){
	circulerLeftShift(0x42,1);
	circulerRightShift(0x42,1);
}

AABBCCDD
for(i=0;i<4;i++){
	rev =rev<<8;
	rev |= (num>>(i*8))&0xFF;
}
// Program 9: Shifting bytr from LSB to MSB
#include<stdio.h>

void byteShifte(unsigned int value){
    int i =0;
	unsigned int output = 0;
	printf("0x%X\n",value);
	for(i=0;i<4;i++){
		output = (output << 8);
		output |= ((value >> (8*i)) &0xFF);
	}
	printf("0x%X\n",output);
}	
0xDDCCBBAA
int main(void){
	byteShifte(0xAABBCCDD);
}

// Program 10: Insert Element in Array
#include <stdio.h>

void insertElement(int *array, int value, int *size, int pos){
	int i;
	
	for(i = *size; pos < i; i--){
		array[i] = array[i-1];
	}
	
	array[pos] = value;
	(*size)++;
}

int main(void){
	int array[10] ={1,2,3,4,5,6};
	int count = 6;
	int i=0;
	insertElement(array,10,&count,3);
	insertElement(array,20,&count,7);
	for(i=0;i<count;i++){
		printf("%d \t ",array[i]);
	}
}

// Program 11: Repepatative Char in String
#include<stdio.h>

void findRepetativeChar(char *array, int size){
	int i,j;
	for(i=0;i<=size;i++){
		for(j=i+1;j<=size;j++){
			if(array[i] == array[j]){
				printf("Repatative Char = %c\n",array[i]);
			//	return;
			}
		}
	}
}

int main(void){
	char array[]="sudamAnilVagareTavahi";
	findRepetativeChar(array,sizeof(array)-2);
}

// Program 12: Find the Number is power of 2
#include<stdio.h>

void findPowerOf2(int num){
	num &= (num-1)
	if(num){
	   printf("Number is power of 2\n");
	}else{
	   printf("Number is not power of 2\n");
	}
}

int main(void){
	
	findPowerOf2(64);
	findPowerOf2(100);
}

// Program 13: Count Set bit
#include<stdio.h>

void bitSet(int num){
	int count = 0;
	while(num){
	  count += num & 1;
	  num = num>>1;
	}
	printf("Count = %d",count);
}

int main(void){
	bitSet(14);
}

// Program 14: Swap Number
#include<stdio.h>

void swapNum(int a, int b){
	a = a+b;
	b = a-b;
	a = a-b;
	printf("a = %d",a);
	printf("b = %d",b);
}

int main(void){
	swapNum(100,200);
}

// Program 15: Find Memory Endianness
#include<stdio.h>
 void findIndianns(void){
	 int num = 0x01;
	 if(*(char*)&num){
		 printf("Littel Endien \n");
	 }else{
		 printf("Big endien \n");
	 }
 }
 
 int main(void){
	findIndianns(); 
 }
 
 // Program 16: Nibble Shift
 #include<stdio.h>
  void nibalShift(unsigned int num){
	  int value = 0;
	  int i;
	  
	  for(i=0;i<8;i++){
		  value = (value << 4);
		  value |= (num >> (4*i))&0x0F;
	  }
	  printf("0x%X",value);
  }
  
  int main(void){
	  nibalShift(0x12345678);
  }
  
   // Program 17: Find the Struct size
  #include<stdio.h>
  
  void findStrcutSize(void){
	  typedef struct{
		  int a;
		  int b;
		  int c;
		  char d;
	  }StructVer;
	  StructVer stSize;
	  
	  int size;
	  size = ((char*)(&stSize+1))-(char*)&stSize; 
	  printf("size = %d", size);
  }
  
  int main(void){
	  
	  findStrcutSize();
  }
  
  // Program 18: Bit Set, Clr, Tlg
  
  // Program 19: Find Char Frequency
  #include<stio.h>
   void findCharFreq(void){
	   char array[] ={SudamAnilVagareJohnsonControl};
	   int i =0 ;
	   in temp[255]={0};
	   for(i=0;i<sizeof(array)-1;i++){
		   temp[(int)array[i]]++;
	   }
	   for(i=0;i<255;i++){
		   
		   if(temp[i]>0){
			   printf("%c = %d",i,temp[i]);
		   }
		   
	   }	   
   }
   
    int main(void){
	  
	  findCharFreq();
  }
  
  // Pogram 20: Callback function
    #include<stio.h>
	
	void operation(int a, int b, void (*ptr)(int, int)){
		ptr(a,b);
		
	}
    
	void addition(int a, int b){
		printf("Sum = %d\n",a+b);
	}
	
	int main(void){
	  
	  findCharFreq(100,200,&addition);
   }
   
 // Program 21: Dimond Pattern
   #include<stdio.h>
    void starPattern(void){
		// Trangle
      int i,j,n=5;
	  
	  for(i=1;i<=n;i++){
		  for(j=i;j<n;j++){
			  printf(" ");
		  }
		  for(j=1;j<(n*i-1);j++){
			  printf("*");
		  }
		  printf("\n");
	  }
	  n =n-1;
	  for(i=n;i>=1;i--){
		  for(j=i;j<=n;j++){
			  printf(" ");
	      }
		  for(j=1;j<=(i*2-1);j++){
			  printf("*");
		  }
		  printf("\n");
	  }
    }
	
   int main(void){
	  
	  starPattern();
   }
   
   // Program 22: Sum of digit
   #include<stdio.h>
   
   void sumOfDigit(void){
	   int num= 12345;
	   int sum = 0;
	   while(num>0){
		    
			sum += (num%10)
		    num =num/10;
	   }
	   printf("%d",sum);
   }
   
   int main(void){
	  
	  sumOfDigit();
   }
   
   // Program 23: Revers the Bit
   #include<stdio.h>
   void printBin(unsigned int num){
	   int i =0;
	   for(i=0;i<32;i++){		   
		   printf("%d",(num>>i&0x01));
		   if(!(i%4)){
			   printf(" ");
		   }
	   }
   }
   void revBit(void){
	   unsigned int num = 0x12345678;
	   unsigned int rev;
	   printBin(num);
	   for(i=0;i<32;i++){
		   
		   rev = (rev <<i);
 		   rev |= (num >>i)&0x01;
	   }
	   printBin(rev);
	   
   }
    int main(void){
	  
	  revBit();
   }
   
 // Program 24: Count The Num
      #include<stdio.h>
	  
	  void countTheDigit(void){
	     int count =0;
		 int num =12305;
         
		 if(num == 0){
			 printf("Count = 1");
		 }else{
			 while(num){
				 num = num/10;
				 count++;
			 }
			printf("Count = %d",count); 
		 }
		 
	  }
   int main(void){
	  
	  countTheDigit();
   }
   
 // Program 25: Findout String length With out strlen

#include<stdio.h>

void findStrlen(void){
   char array[] ="sudam Anil Vagare";
   int count = 0;
   int i =0 ;
   while(array[i] != '\0'){
	   count++;
	   i++;
   }
   printf("Count = %d",count);
}	

int main(void){  
    findStrlen();
}

// Program 26: Check string is Anogram| Legth and Frequency of Char is same

#include<stdio.h>

void checkString(void){
	char s1[] = "Sudam Anil Vagare";
	char s2[] = "Sudam Anil Vagare";
	int i;
	int array[255]={0};
	int set =0;
	for(i = 0;i<sizeof(s1);i++){
         array[(int)s1[i]]++;		
	}
	for(i = 0;i<sizeof(s2);i++){
         array[(int)s2[i]]--;		
	}
	for(i=0;i<255;i++){
		if(array[i] != 0){
			set =1;
			break;
		}
	}
	if(set){
	   printf("Strings are not Anogram \n"); 
	}else{
	    printf("Strings are Anogram \n"); 
	}
}
int main(void){  
    checkString();
}

// Program 27: Find the frist non repating char
#include<stdio.h>

void noRepChar(void){
	char s1[]="SudamAnilVagares";
	int i;
	int array[255] ={0};
	for(i=0;i<sizeof(s1);i++){
		array[(int)s1[i]]++;
	}
	for(i=0;i<sizeof(s1);i++){
		if(array[(int)s1[i]] == 1){
			printf("%c",s1[i]);
		}
	}
}

int main(void){  
    noRepChar();
}

// Program 28: Find the frist non repating char
#include<stdio.h>

void noRepChar(void){
	char s1[]="SudamAniluVagareS";
	int i;
	int array[255] ={0};
	for(i=0;i<sizeof(s1);i++){
		array[(int)s1[i]]++;
	}
	for(i=0;i<sizeof(s1);i++){
		if(array[(int)s1[i]] == 1){
			printf("%c",s1[i]);
			break;
		}
	}
}

int main(void){  
    noRepChar();
}
   
   
28) Pointer

	i) NULL Pointer
		A pointer that does not point a valid object or fumction.

		int *Ptr = NULL;

		if(Ptr != NULL){
			printf("%d",*Ptr);
		}
		
	ii) Wild Pointer
	   Uninstalized ponter called as Wild ponter
	   int *Ptr;   
	   
	iii) Void Pointer
	   Hold the address of any object
	   
	   void *Ptr;
	   int a = 100;
	   Ptr = &a;
	   
	   printf("%d",*(int*)Ptr);
   

29) Pointer increment
i)
	int array[]={10,20,30};
	int *Ptr = &array;

	printf("%d",*Ptr);  // 10
	Ptr++;
	printf("%d",*Ptr);  // 20
	
ii) 
	int array[]={10,20,30};
	int *Ptr = &array;
	
	printf("%d",*(Ptr+2));  // 30
	*Ptr++;
	printf("%d",*Ptr);      // 11
	

30)
// Pointer to constant data
const int *Ptr =&x  // 

//Constant pointer
int *const Ptr = &x;	

// Constant pointer to Constant
const int *const Ptr;
	
	

const int *ptr;// pointer to constant data
int const *Ptr;
int *const Ptr; // constant pointer to data
const int *const Ptr; //constant pointer constant data



31) Array of function pointer
#include<stdio.h>

void add(int a,int b){
	printf("%d\n",a+b);
}

void sub(int a, int b){
	printf("%d\n",a-b);
}
void mul(int a, int b){
	printf("%d\n",a*b);
}
int main()
{
   void (*ptr[3])(int, int);
   ptr[0] = add;
   ptr[1] = sub;
   ptr[2] = mul;  
   ptr[0](10,20);   
   ptr[1](20,5);
   ptr[2](10,20);    
}

32) Array of pointer
#include<stdio.h>
void findLargestMark(int **ptr,int *size,int count){
	int i = 0,j = 0;
	int max = 0;
	
	for(i=0;i<count;i++){
		for(j=0;j<size[i];j++){
			if(ptr[i][j] > max ){
				max = ptr[i][j];
			}
		}
	}
	printf("%d\n",max);
}
int main()
{
   int *ptr[3];
   int classA[] = {1,2,3,4};
   int classB[] = {4,5,6};
   int classC[] = {1,32,5,6,0};   
   int size[3] ={4,3,5};
   int count = 3;
   
   ptr[0] = classA;
   ptr[1] = classB;
   ptr[2] = classC;
   findLargestMark(ptr,size,count);
}

33) Bit Fild
#include<stdio.h>
 typedef struct{
	 unsigned int bit0:2;
	 unsigned int bit1:2;
	 unsigned int bit2:2;
	 unsigned int bit3:2;
	 unsigned int data;
	 
 }Temp_t;
 
int main()
{
   Temp_t temp;
   temp.bit0 = 0;
   temp.bit1 = 1;
   temp.bit2 = 2;
   temp.bit3 = 1;
   temp.data = 10;
   printf("bit2 = %d",temp.bit2);
}


34) union
#include<stdio.h>
 typedef union{
	 struct{
	    unsigned char bit0:2;
	    unsigned char bit1:2;
	    unsigned char bit2:2;
	    unsigned char bit3:2;
	 };
	 unsigned char data;	 
 }Temp_t;
 
int main()
{
   Temp_t temp;
   temp.bit0 = 2;
   temp.bit3 = 1;
   printf("%d",temp.data);
}

35) find L number

#include<iostream>
using namespace std;

void findNum(void){
	int array[]={20,30,50,60,10,100,400,300};
	int lNum;
	int sNum,i;
	sNum=array[0];
    lNum=array[0];
	
	for(i=0;i<(sizeof(array)/sizeof(int));i++){
		if(array[i]<sNum){
			sNum = array[i];
		}
		if(array[i]>lNum){
			lNum = array[i];
		}
	}
	cout<<"sNum = "<<sNum<<endl;
	cout<<"lNum = "<<lNum;
	
}

int main(){
	findNum();
}

36) // Prime number check
#include <stdio.h>

void checkPrimeNum(int num){
   int i =0;
   for(i=2;i<num;i++){
       if(num%i == 0){
           printf("Number is not prime\n");
           return;
       }
   }
   printf("Number isprime\n");
}

int main()
{
    checkPrimeNum(9);
checkPrimeNum(17);
    return 0;
}


