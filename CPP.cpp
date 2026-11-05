
1) calss is userdefined function, Blue print of object, class contanis veriable and function.
 class demo{
	 // by default vaeriable are private
	 int x;
	 public :
	   int a;
	 private: 
	 int b;
	 
	 public:
	 void showFun(void){
	    std::cout<<a<<std::endl;	 
	 }
 };
 
2)Acess specifier in calss
  -Private    : Acess with in class
  -Protected  :  with in class and child class only
  -Public     : with in and outside 
  
  
class Demo{
      private:
	    int a;    
	  protected:
	    int b;
	  public:
	     int c;
	  
	  void setValue(void){
	      a = 10; b = 20; c = 30;
	  }
	  void showValue(void){
	      std::cout<<a<<std::endl;
	      std::cout<<b<<std::endl;
	      std::cout<<c<<std::endl;
	  }	  
   };
   
   class child : public Demo{
       public:
       void acess(){
          b =300; c = 400; 
       }
 };
  

3) Friend function/class: A frind class is spectial type of class that can acess the private
   and protected member of anthor class 
-- Friend function can acessany memberof the class to which it is a frind.
-- friend function not acess member of class directly
-- it should not defineed with membership lable.
// Online C++ compiler to run C++ program online
#include <iostream>

class Demo{
   private:
   int a=100;
   
   friend class demo1;
   friend void show1(void);
};

class demo1{
    public:
    void show(){
        Demo d2;
        std::cout<<d2.a<<std::endl;
    }
};
void show1(){
    Demo d3;
    std::cout<<d3.a<<std::endl;
}


int main() {
    // Write C++ code here
    demo1 d1;
    Demo  d4;
    d1.show();
    show1();
    return 0;
}

4) Constructor is a special type of function of a class that automatically gets called when an objaect crated
   - it should same name as the class
   - no return type
   - automatically invoked when object is crated
   - must be public
   
   Type of Constructor
   - Default Constructor
   - Paramterized Constructor
   - copy Constructor
   
   #include <iostream>
	class student{
		private :
		int a;
		
		public:
		student(int r){
			a = r;
			std::cout<<a<<std::endl;
		}
	};
	int main() {
		// Write C++ code here
		student s1(100);
		return 0;
	}
	 - copy Constructor

	 #include<iostream>
	 using namespace std;
	 
	 class student{
		 private:
		 int x;
		 int y;
		 public:
		student(int a, int b){ // Parameteried Constructor
           x = a; 
		   y = b;
		}			
		student(const student &obj){
			x = obj.x;
			y = obj.y;
		}
	 };
	 int main(){
		 student s1(10,20);
		 student s2 = s1;
		 
	 }
5) A Destructor is a special member function in the class that automatically called when object goes out of scope
 or deleted
  - same name as class but with a ~ before it
  - No paramter, no return type
  - only one destructor per class
  - No overloading allowed  
  
  class Demo{
	  private :
	   int a;
	   
	  public:
	  Demo(){
		// Constructor body  
	  }
	  ~Demo(){
		// Destructor body 
	  }
  }
  
  int main(){
	  Demo d1;
	  Demo d2;
	  
	  return 0;
  }
  // frist called d2 distructor and then d1
 
6) Inheritance is a mechanism in object orianted programming that allows one class to acquire the properties
and behaviours of a another class 

	- Base class (Parent class)
    - Derived class (child class)	
	
	// Online C++ compiler to run C++ program online
	#include <iostream>

	class UART{
		public:
		void  initUart(void){
			std::cout<<"Uart init done"<<std::endl;
		}
	};

	class UartDebug: public UART{
		public:
		void SendData(){
			std::cout<<"UART Send Data";
		}
	};
	int main() {
	   UartDebug b1;
	   b1.initUart();
	   b1.SendData();
		return 0;
	}
	
7) Type of inheritance
   - single inheritance: A drived class inherits from one base class
      ex. BC --> DC
   - Mulltiple inheritance: A drivedclass inhertes from more than one base class
     Ex. BC----|
	            ----> DC
	     BC----| 
   - Multilevel inheritance: A class inherits from drived class forming a chain'
     Ex. BC --> DC --> DC1 --> DC2
   - Hierachical inheritance: Mulltiple classes inherits from one base class
         BC --> DC1
            --> DC2
            --> DC3

8) Single inheritance:
  class base{
	  public:
	  int add(int a, int b){
		  return(a+b);
	  }
  };
  
  class drived: private base{ // privete : child class only call add() funtion no one other.
	  public:
	  int fun(int a, int b){
		  return(add(a,b));
	  }
  };
  
  int main(){
	  drived d1;
	  std::cout<<d1.fun(10,20);
  }
  
9) Mulltiple inheritance:

// Online C++ compiler to run C++ program online
#include <iostream>

class A{
	public:
	void show(void){
		std::cout<<"Show A"<<std::endl;
	}
};
class B{
	public:
	void show(void){
		std::cout<<"Show B"<<std::endl;
	}
};

class drived : public A, public B{
	public:
	void show(void){
		std::cout<<"show C"<<std::endl;
	}
};
 			
int main(){
	drived d1;
    d1.A::show();
	d1.B::show();
	d1.drived::show();
}

10) Encapsulation: Means wrapping the member(veriable) and methods(function) together into a single class
    and controlling acess to that class
	
	
11) Polymorphism:  One function or object behaves a diffrent way depaneding on situation
// complie time Polymorphism: Fonction overloading
// Defining the mulltiple function with the same name but diffrent parameter number or type.
class print{
	public:
	void disply(int a){
		std::cout<<a;
	}
	void display(double b){
		std::cout<<b;
	}
	int add(int a, intb){
		return(a+b);
	}
	double add(double a, double b){
		return(a+b);
	}
}

12) Method overriding(Runtime Polymorphism)
    - Method overrinding means redefining a function of the base class in the derived class with the same function name, same
      parameter list and same return type.	
class base{
	public:
	 void show(){
		 std::cout<<"base"<<std::endl;
	 }
};
class derived {
	public:
	void show(){
		std::cout<<"derived"<<std::endl;
	}
};

int main(){
	derived d1;
	d1.show(); // derived class show calling
    d1.base::show();// base class show() calling.
}


13) Virtual function amd method overriding

// Online C++ compiler to run C++ program online
#include <iostream>

class base{
   public:
	 virtual void show(void){
	   std::cout<<"Base Show()"<<std::endl;
	}	
};
 
class derive: public base{
   public:
       void show(void){
         std::cout<<"derived show()"<<std::endl;
	}	  
};

int main(){
	base *b1;
	derive d1;
	b1 = &d1;
	b1->show(); // derived class show() calling if user remove the virtual keyword base class show() calling 

    return 0;
}

14) Opertor overloding:Means giving additional meaning to the oprater for user-defined objaect
//Operator that cannot be overloded
., ::, ?,:, *, sizeof, typeid,,
// Online C++ compiler to run C++ program online
#include <iostream>
class chanel{
    public:
	int data;
	public:
	 chanel(int value){
		data = value;
	}
	
	void operator++(){
		data++;
	}
};

int main(){
	chanel c1(100);
	++c1;
	std::cout<<c1.data<<std::endl;
	c1.operator++();
		std::cout<<c1.data<<std::endl;
	return 0;
}

15) OOP(Object-Oriented Programming): Is used to design softwsre around object- Which cobine data and behavior.
 - Easier to maintains
 - More Reuseable
 
 - Inheritance
 - Encapsulation
 - Polymorphism
 - Abstraction

16) Abstraction: Showing only the necessary details and hiding the internal working of the program.
    - A class contsining pure virtual function is an abstract class
	- We can not create the object of abstract class

// Online C++ compiler to run C++ program online
#include <iostream>

  class Car{
	  private:
	  int speed;
	  
	  public:
	   void setSpeed(int s){
		   speed = s;
	   }
	   void showSpeed(){
		   std::cout<<speed;
	   }
  };
  
  int main(void){
	  Car c1;
	  c1.setSpeed(100);
	  c1.showSpeed();
  }
  
  ///////////////////////
// Online C++ compiler to run C++ program online
#include <iostream>
 class shape{
	  
	  public:
	  virtual void Drow()=0;
  };
  
  class Circual: public shape{
	  
	  public:
	  void Drow(){
		  std::cout<<"Circual";
	  }
	  
  };
  
  int main(){
	  shape *s;
	  Circual c1;
	  s = &c1;
	  s->Drow();
	  return 0;
  }
  
17) namespace: is collection of class, member and methods
 // Defining namespace
  #include<iostream>
 using namespace std;
 
 namespace demo{
	 // Code declaration
	 void display(void){
		 cout<< "display"<<endl;
	 }
	 void hello(void){
		 cout<<"Hello"<<endl;
	 }
	 class car{
		 public:
		   void showSpeed(int s){
			   cout<<s<<endl;
		   }
	 };
 }
 
 using namespace demo;
 
 int main(){
	 car c1;
	 c1.showSpeed(100);
	 return 0;
 }
 
 /* --------------------------------------*/
 using namespace demo;
 
 #include<iostream>
 
 using namespace std;
 
 int main(){
	 cout<<"namespace Example"<<endl;
	 return 0;
 }
 
 /*---------------------------------------*/
 
18) Function call:
  stack memory Store
   - Function Parameter
   - Local Variable
   - Return Address
   - LIFO
   
   #include<iostream>
   using namespace std;
   void fun2(int s){
	   cout<<s<<endl;
   }
   void fun1(int a, int b){
	   int sum =0;
	   sum =a+b;
	   fun2(sum);
   }
   
   int main(){
	   int num1 = 100;
	   int num2 = 200;
	   fun1(num1, num2);
	   return 0;
   }
  // store order: main()--> fun1() --> fun2()
  // Return order: fun2() --> fun1() --> main()

//Stack Memory
-----------------
|               |
|               |
-----------------
| fun2()        |
| result = 30   |
-----------------
| fun1()        |
| a = 10        |
| b = 20        |
| sum = 30      |
-----------------
| main()        |
| num1 = 10     |
| num2 = 20     |
-----------------



#include<iostream>
namespace demo{
   class temp{
       void show(void){
		   std::cout<<"temp class";
	   }
   };	   
};
using namespace demo;

int main(){
	temp t1;
	t1.show();
	
}

19)  Why C++ is preferred over C Programming language

- C is procedural language that use a top-down approach for problem solving
- C++ is Object-Oriented superset of C, introducing E,A,P,E. Fallow the botttom-up approach.

20) What is static data member


 // i) static local variable
 void counter(){
	 static int count = 0;
	 cout<<count;
 }
 - initialzed only ones
 - Scope is limited to the function, but lifetime is the entire program.
 
 // ii) static gloable veriable
 static int count;
 - scope is limited to the file.
 - Not accessible from other file (even  with extern) 
 
 // iii) Static class member 
- static data member share one copy across all class instances
- memory for static members is allocated ones at the class level
- must defined outside the class
#include<iostream>

class student{
	static int count;
	
	public:
	 student(){
		count++;
	}
	void showCount(void){
		std::cout<< "Number of student object:" << count<<std::endl;
	}
};
int student::count = 0;
int main(){
	student s1, s2, s3;
	s1.showCount();
}


21) // this: pointer in C++ : this pointer in C++ that point to the the current object

#include<iostream>
using namespace std;
class student{
    int age;
	int value;
    public:
    void setAge(int s){
       this->age = s;
	}	
	void setValue(int value){
		value = value;
		this->value = value;   // when parameter name and member name are same that time comiler may assigen the same value itself that time use this
	}
      // "this " pinter point to the object
    void showAge(){
	   cout<<age;
	}		
	
};

int main(){
    student s1;
    s1.setAge(25);
    s1.showAge();	
	return 0;
}

22) what is inline function
- An inline fuction whare the compiler tries to replace the function call with the actual function code
  to redues the function call time
  - Why use the inline
  - Inline function mainaly used for
    - small functions'
	- Faster Execution
	- Avoid function call Overhead
	
	Disadvatages
	- Comiler may ignor the inline
	- To many inline function can increase memory usage
	- When function written inside the class, it becomes inline automatically
	
	class Test{	
		public:
		void show(){                 // inline function
			cout<<"show function";		
		}
		
	};

   - if function outside the class use inline keyword manually
   class Test{
	   public:
	   inline void show(void);
   };
   
   inline void Test::show(void){
	   cout<<"show Function";
   }

23) Exception in C++
  - Exception is any abnormal behaviour, run time Error
     Ex. Devied by 0, Array bound acess.
	 - try
	 - catch
	 - throw
	 
	 // try and catch must be write togather
	 int i =3;
	 try{
		 if(i ==0)
		 throw 0;
	     if(i==1)
		 throw 1;
	     if(i==3)
		 throw 3;
	 }
	 catch(int value){
		 
		 cout<<"Excpation Code: "<<value;
	 }
	 catch(double value){
		 
		 cout<<"Excpation Code: "<<value;
	 }
	 
	 //  Catch All Exception: can be catch all type of paramter
	     catch(...){
			 
		 }
		 
	////////////////
// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
// this pointer: this pointer is point to the current object

class demo{
   public:
      void divistion(int a, int b){
	      
         try{
             if(b==0){
			    throw (10);
			 }
			 if(b==1){
			    throw (10.5);
			 }
			 if(b==2){
			    throw('a');
			 }
             cout<<a/b<<endl;
         }
         catch(int a){
            cout<<"b = 0"<<endl;
         }
         catch(double a){
            cout<<"b = 1"<<endl;
         }
         catch(...){
            cout<<"b = 2"<<endl;
        }		 
	  }
};


int main(){
   demo d1,d2,d3;
   d1.divistion(10,0);
d1.divistion(10,1);
d1.divistion(10,2);
d1.divistion(10,3);
   return 0;
}


24) VECTOR: Vector is the dynamic array from the STL that automaticaly be resize when add or remove the element

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


		
	 













