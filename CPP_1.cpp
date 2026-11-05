1)Dimond Problem class

               Vehical
			   
	Car                       Truck

               pickupTruck	

#include <iostream>
using namespace std;
  
class Vehical{
	
	public:
	void show(){
		cout<<"Vehical show";
	}
};

class Car: virtual public Vehical{
     public:
     void fun1(){
          cout<<"Car Show";
	 }		 
};

class Truck:virtual public Vehical{
	 public:
	 void fun2(){
		 cout<<"Truck show";
	 }
};
class pickupTruck: public Car, public Truck{
      public:
      void fun3(){
	    cout<<"pickupTruck";
	  }		  
	
};

int main(){
	pickupTruck Pt1;
	Pt1.show(); 
	return 0;
}


2) You are creating a banking application with two classes 'Account' and 'Transaction'. The Transaction class need to check the private blance
of an account to see if thre are eniugh founds for a widraw. How would you allow the Transaction class to acess the blance while
keeping the account detalis secure?

#include<iostream>

using namespace std;


class Account{
   private:
      int blance;
   
   public:
   friend class Transtion;
     Account(int amount){
		 blance = amount;
	 }
	 void showBlance(){
		 cout<<"Blance: "<<blance<<endl;
	 }
};

class Transtion{
	public:
	void widrowMonay(Account *Ac, int value){
	     if(Ac->blance<value){
           cout<<"insuffesment blance"<<endl;			 
	     }else{
			 Ac->blance -= value;
			 cout<<"Account balance is: "<<Ac->blance<<endl;
		 }
	}
};

int main(){
    Transtion T1;
	Account A1(500);
	A1.showBlance();
	T1.widrowMonay(&A1,200);
   	
}

3)What is call by value , call by refrance & call by address

- Call by value: Copies the actual parameter to the function, changes inside the fuction,
   changes inside the function don't affect the orignal value
- call by address: Passes the memory adress, allowing direct modification of the orignal value
- Call by refrance: pass the veriable function give the anator name to the variable.

 #include <iostream>
  using namespace std;
  
  void fun1(int value){
	  value++;
	  cout<<value<<endl;
  }
  void fun2(int *value){
	  *value=10;
	  cout<<*value<<endl;
  }
  int main(){
	  int ver=100,ver1 = 200;
	  cout<<ver<<endl;
	  fun1(ver);
	  cout<<ver<<endl;
	  
	  cout<<ver1<<endl;
	  fun2(&ver1);
	  cout<<ver1<<endl;
  }
  
#include<iostream>
using namespace std;

void valueSet(int x, int &y, int *z){
   x = 100;
   y = 200;
   *z = 300;
}

int main(){
   int a =10,b=20,c=30;
   valueSet(a,b,&c);
   cout<<"a = "<<a<<"  b = "<<b<<"  c = "<<c<<endl;   
   return 0;
}
4) Write a program to check if Two string are Anagram or not

// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;

int checkAnogram(string s1, string s2){
	char array[255]={0};
	if((s1.length()) != (s2.length())){
		printf("string are not anagram\n");
	    return 0;
	}
	for(int i=0; i<s1.length();i++){
	    array[(int)s1[i]]++;
	}
	for(int i=0; i<s2.length();i++){
	    array[(int)s2[i]]--;
	}
	for(int i=0; i<s1.length();i++){
	    if(array[(int)s1[i]] != 0){
	        return 0;
	    }
	}
	return 1;
}

int main(){
	string s1 ="sudam";
	string s2 ="sudam";
	if(checkAnogram(s1,s2)){
	 cout<<"String is Anogram";   
	}else{
	    cout<<"string is not Anogram";
	}
	
}

#include<stdio.h>
#include<string.h>
int stringAnogram(char *s1, char *s2){
    int i =0;
    char array[255];
	if(strlen(s1) != strlen(s2)){
		return 0;
	}
	
	for(i =0; i<strlen(s1);i++){
	    array[(int)s1[i]]++;
	}
	for(i =0; i<strlen(s2);i++){
	    array[(int)s2[i]]--;
	}
	for(i=0;i<strlen(s1);i++){
	    if(array[(int)s1[i]] != 0){
	        return 0;
	    }
	}
	return 1;
}
int main(){
	char s1[] ="sudam";
    char s2[] = "sudam";
	if(stringAnogram(s1,s2)){
		printf("string is Anagram");
	}else{
		printf("string is not anagrom");
	}
}

5) Write a program to find the frist nonrepeating charter in string
#include<stdio.h>
#include<string.h>
void checkString(char *s1){
	int i =0;
	char array[255]={0};
	
	for(i=0;i<strlen(s1);i++){
		array[(int)s1[i]]++;
	}
	for(i=0;i<strlen(s1);i++){
		if(array[(int)s1[i]]==1){
			printf("char = %c",s1[i]);
		    return 0;
		}
	}
	return 1;
}
int main(){
	char s1[]="sudamSuda"
	if(checkString(s1)){
		printf("all charter repete more than 1 time");
	}
	return 0;
}
i
6) What is STL(Standared Template Library)
- STL provides built-in data structures like vector, sets and maps. 
- #include<vector>

7) VECTOR: Vector is the dynamic array from the STL that automaticaly be resize when add or remove the element

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;  
int main() {
    // Write C++ code here
    vector <int> v1={1,2,3,4};
    cout<<v1.size()<<endl;
    v1.push_back(10);
    cout<<v1.size()<<endl;

    v1.pop_back();
    cout<<v1.size()<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int main(){
   vector<int> p={1,2,3,4,5};

    for(int i=0;i<p.size();i++)
       cout<<" "<<p[i];
    cout<<endl;
    for(int x:p)         // assign the each value to the x for each itration.
       cout<<" "<<x;
   return 0;
}

7) Write a program to remove duplicate from a sorted array.

#include<iostream>
#include<string>
#define TRUE 1
#define FALSE 0
using namespace std;

void checkDuplicate(string s1){
      int i, j;
	  string s2 = "";
	  bool dupalicate = FALSE;
	  
     for(i =0; i<s1.length();i++){
		  for(j=0;j<s2.length();j++){
			  if(s1[i] == s2[j]){
				  dupalicate = TRUE;
				  break;
			  }
		  }
		  if(dupalicate == FALSE){
			  s2 = s2+s1[i];
		  }
		  dupalicate = FALSE;
	 }	
     cout<<s2;	 
}
int main(){
	string s1 = "Sudama";
	checkDuplicate(s1);
	return 0;
}

8) Find out Missing Number in Array
#include<iostream>
#include<string>
using namespace std;

void findTheMissingNum(void){
     
	 char array[] ={1,2,3,4,6,7};
	 int sum1=0,sum2=0;
	 int i=0;
	 int size= sizeof(array)+1;
	 
	 sum1 =size*(size+1)/2;

     for(i=0; i<sizeof(array);i++)	 {
		 sum2+=array[i];
	 }	 
	 cout<<"missing number:"<<sum1-sum2; 
}


int main(){
	findTheMissingNum();
	return 0;
}

9) BIT: SET, CLR, TLG
#include<iostream>
#include<string>
#define BIT_SET(NUM,POS) (NUM = NUM | (1<<POS))
#define BIT_CLR(NUM,POS) (NUM = NUM & (~(1<<POS)))
#define BIT_TLG(NUM,POS) (NUM = NUM ^ (1<<POS))
using namespace std;

void bitSet(int num, int pos){
	num = num | (1<<pos);
	cout<<num<<endl;
}
void bitClr(int num, int pos){
	num = num & (~(1<<pos));
	cout<<num<<endl;
}
void bitTlg(int num, int pos){
	num = num ^ (1<<pos);
	cout<<num<<endl;
}

int main(){
    int num =10,pos =1;
    
    bitSet(10,3);
	bitClr(12,3);
	bitTlg(10,1);
	BIT_SET(num,pos);
	cout<<num<<endl;
	BIT_CLR(num,pos);
	cout<<num<<endl;
	BIT_TLG(num,pos);
	cout<<num<<endl;
	return 0;
}

10)d to b con

#include<iostream>
using namespace std;

void dTob(int value){
	
	int array[32]={0};
	int i=0,j=0,count=0;
	while(value>0){
		if(value%2){
			array[i] = 1;
		}else{
			array[i] = 0;
		}
		i++;
		value = value>>1;
	}
	
	for(j=(i-1);j>=0;j--){
		cout<<array[j];
		if(array[j]==1){
			count++;
		}
	}
	cout<<":::"<<count;
}

int main(){
	dTob(13);
}

11) Callback function
#include<iostream>
using namespace std;
void sum(int a, int b){
   cout<<(a+b)<<endl;
}

void funPtr(int a, int b, void (*callBack)(int, int)){
	callBack(a,b);
}

int main(){
	funPtr(10,20,&sum);
}

12) find L number

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

13) Queue 

#include<iostream>
using namespace std;

#define SIZE  5
int buffer[SIZE]={0};
int count = 0;
int front = 0;
int rear  = 0;

void enQueue(int num){
     
   if(count == SIZE){
       cout<<"Buffer is full"<<endl;
	   return;
   }	   
   
   buffer[rear] = num;
   rear = (rear + 1) % SIZE;
   count++;
}

int deQueue(void){
   int temp;
   if(count == 0){
	   cout<<"Queue is empty"<<endl;
	   return 0;
   }
   
   temp = buffer[front];
   front = (front + 1) % SIZE;
   count--;
   return temp;
}

void QueueDisplay(void){
	int i =0 , index =0;
	
	index = front;
	cout<<"BUFFER VALUE = ";
	for(i =0; i<count;i++){
		cout<<buffer[index]<<endl;
		index = (index+1)%SIZE;
	}	
}

int main(){
	QueueDisplay();
 	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	QueueDisplay();
	enQueue(60);
	cout<<deQueue()<<endl;
	QueueDisplay();
}


//Stack


#include<iostream>
using namespace std;
#define SIZE 5
void revNumb(int num){
	int rev=0;
	
	while(num>0){
		rev = (rev*10)+(num%10);
		num =num/10;
	}
	cout<<rev<<endl;
}

void stringRev(void){
	char str[]="sudamAnilVagare";
	int size = sizeof(str)-2;
    int i=0;
	char temp;
	
	while(i<size){
		temp = str[i];
		str[i]= str[size];
		str[size] = temp;
		i++;
		size--;
	}
	for(i=0;i<sizeof(str)-1;i++){
		cout<<str[i];
	}	
}

int stack[SIZE];
int rear  = -1;
void push(int value){
	if(rear == (SIZE-1)){
		cout<<"stack is full";
		return;
	}
	rear++;
	stack[rear] = value;	
}

int pop(void){
	int temp;
	if(rear== -1){
		cout<<"stack is empty";
		return 0;
	}
	
	temp = stack[rear];
    rear--;
	return temp;
}

void display(){
	int i;
	if(rear == -1){
		cout<<"Stack is empty"<<endl;
	}
	for(i=0;i<=rear;i++){
		cout<<stack[i]<<endl;
	}
}

int main(){
	revNumb(12345);
	stringRev();
	cout<<endl;
	push(10);
	push(20);
	push(30);
	display();
	cout<<pop();
	display();
    return 0;	
}