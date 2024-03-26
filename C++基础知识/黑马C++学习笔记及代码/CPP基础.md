#   cpp基础

## CPP内存四区

* 代码区：二进制代码：操作系统管理（CPU执行的机器指令，共享的，只读的）
* 全局区：存放全局变量 静态变量 常量（全局常量和字符串常量） 数据在程序结束后释放
* 栈区：编译器自动释放 存参数值，局部变量，局部常量，**不要返回局部变量**
* 堆区：程序员分配和释放，程序结束操作系统回收 new delete

## 数组

  通常是一些相同类型元素的集合，存放在连续的内存空间中 

* c++里面越界访问（stl中可能会导致迭代器失效）是可以的，但是要小心，因为可能会更改其他内存，如果这个内存保存的有变量，可能会引起错误

  ```cpp
  int example[5]; //栈上创建数组
  for (int i = 0; i < 6; i++) 
  {
      cout << *(example+i) << endl;
  } //可以访问example[5]，但是其值是不确定的
  ```

* 上面的*(examlpe+i)等价于  *(int *)((char *)example + 4 * i)，注意char型指针和int型指针所占内存的区别，但我个人觉得后一种方式多此一举了

* for循环中一般用< 而不是 <= 后者需要两次比较

* 使用int *another= new int[] 在**堆上创建数组**，堆栈上创建的数组**生存周期**不同，堆上只由**delete**销毁或者**程序结束**时其才会被销毁；而栈上的数组在**跳出作用域**就会被销毁（例如函数中的局部数组变量）

* 堆上创建的数组使用内存间接寻址，another存的是数组的首地址

* 如果函数要返回数组，就必须用new创建数组（生存周期）

* 栈上的数组元素数量计算方法：int count = sizeof(example) / sizeof(example[0])

静态数组与动态数组

```cpp
int arr[5];//静态数组

cin << size;
int* arr = new int[size];//动态数组
```



### 二维数组

```cpp
int arr[][2] = { 1,2,3,4,5,6 };
arr //二维数组的首地址
arr[0] //
```







## 字符串（string）

可能用到，游戏引擎字体渲染

* const char *name = "zhou"; 一般定义字符串为常量类型，不会被改变
* 这样输出字符串直接cout << name << endl; 因为在内存中，存储完zhou后会存一个‘\0’**空终止符**
* cpp里面的string标准库专门用来处理字符串，直接创建：string name = “zhou”，可以使用name.size()取元素数量，还有很多其他的api可以调用

**string  c = "abd" + "b"是非法的，因为右边是两个char[]型数据的相加，但是C++标准库中没有实现“+”号对于char[]类型的重载以支持char[] + char[]操作。**解解决方法：

```cpp
string  c = "abd" + "b";//错误，char[]型数据不能相加，=没有重载
string a = "abd";
string c = a + "b";//正确，标准库中重载了string类和char[]的加法
string c = a + "b" + "t" + "f"; //这也是正确的
```



## 设置随机数

```cpp
#include <ctime>

int main(){
    std::srand(std::time(null)); //用当前时间作为随机数种子
    int random = std::rand(); //设置随机数
}
```



## C++中的关键字

### const关键字

声明某些变量定义之后就不能改变，比如最大MAX_AGE  

用法：const int 、const int *（int const *）、int *const（const *int）、const int *const、类内的const成员方法

* ```cpp
  const int MAX_AGE = 90;
  const int *a = new int(5); //a所指向的内存所存储的内容不能改变，但可以改变a的指向
  int const *a = new int(5); //和上面等价
  *a = 2; //错误，不能改变a指向的内存存的内容
  a = (int *)&MAX_AGE; //正确，可以改变a的指向
  
  int *const b = new int(5); //a的指向不能改变，但可以改变a指向的内存的内容
  const *int b = new int(5); //和上面等价
  b = &MAX_AGE; //错误，不能改变b的指向
  *b = 30; //正确，可以改变b指向的内存的内容
  ```

* 忽略int 看const修饰的内容，若是*a，则表示a所指向的内存所存储的内容不能改变；若是a，则表示a的指向不能改变

  ```cpp
  const int *const a = new int; //a的指向与a指向的内存的内容都不会被改变
  ```

* 类内的const成员方法：

  ```cpp
  class Entity
  {
  public:
      int m_X, m_Y;
  
  private:
      int Get() const // 类成员函数的const用法，代表在成员函数中不能修改类的成员变量
      {
          m_X = 2; // 错误，不能修改类的成员变量
          return m_X;
      }
  };
  ```

  并且在const成员方法内只能调用const成员方法，不能调用非const成员方法，因为其可能会改变非mutable的成员变量

  只有**成员函数**（包括**非静态成员函数**和**类成员函数**）可以声明为const。普通的全局函数或静态成员函数不能被声明为const。

### mutable关键字

用处1，**类的const成员方法**；用处2，**Lambda表达式**

* 在类中声明某一成员方法是const后，仍然想要在此方法内改变类的成员变量，那么将此成员变量声明为mutable即可实现。

  ```cpp
  class Entity
  {
  public:
      int m_X, m_Y;
      mutable int var; // 可以改变的类成员变量
  
  private:
      int Get() const // 类成员函数的const用法，代表在成员函数中不能修改类的成员变量
      {
          m_X = 2; // 错误，不能修改类的成员变量
          var = 3; // var是可变的成员变量，可以在const方法中改变
          return m_X;
      }
  };
  ```

* Lambda表达式（很少的情况下会使用；等学了再补这块.........）

### new关键字

调用new的过程：

1. 找到连续的四字节内存（如果new 一个int型数据的话）（不是顺序寻找，有一个空闲列表，存储有空闲字节的内存）

2. 之后返回一个指向那个内存地址的指针

   C++中不能使用变量来定义数组的长度：

```cpp
int lenth;
cin >> lenth;
int b[lenth];  //非法，编译时报错
```

​	在 C++ 中，数组的长度必须是一个常量表达式，即在编译时就能确定的值，即如下所示：

```cpp
int length;
cin >> length;
int *b = new int[length];
```

new 和 malloc

```cpp
Entity *e = new Entity(); 
Entity *e1 = (Entity*)malloc(sizeof(Entity))
```

两者的区别:

* new不仅分配了Entity所需要的内存，还调用了构造函数；new自动地根据所申请内存空间的类型进行强制转换
* malloc只分配所需内存；只返回 `void*` 类型的指针，需要手动进行类型转换

### 隐式转换与explicit关键字（不经常使用）

如下定义了两个构造函数：

```cpp
Entity(const string &name)
    : m_Name(name), m_Age(-1) {}
Entity(int age)
    : m_Name("Unknown"), m_Age(age) {}
```

定义类的对象：

```cpp
Entity a = 22; //这里隐式的将int型转换为Entity型，并且默认只能转换一次
Entity a(22); //直接生成对象
```

如果在构造函数前加上explicit关键字：

```cpp
explicit Entity(const string &name)
    : m_Name(name), m_Age(-1) {}
explicit Entity(int age)
    : m_Name("Unknown"), m_Age(age) {}
```

则只能使用Entity a(22);创建类的实例

## 操作符与操作符重载

如果想要实现两个二维向量的加法，可以使用操作符重载实现：

```cpp
public:
    float x, y;

public:
    speed(float x, float y)
        : x(x), y(y){};
    speed Add(const speed &other) const
    {
        return speed(x + other.x, x + other.y);
    }

    speed operator+(const speed &other) const
    {
        return Add(other);
    }
```

主函数中：

```cpp
speed a(100, 20);
speed b(70, 20);
speed c1 = b.Add(a);
speed c2 = a + b; // c1,c2实现相同的目的
```



## 内存泄漏问题

1. 隐式内存泄漏 动态内存申请后一定要记得释放
2. 丢失内存块地址  

```cpp
#include <iostream>

int main()
{
    int *ptr;
    int num = 123;
    ptr = (int *)malloc(sizeof(int));
    ptr = &num;
    free(ptr); //错误，尝试释放局部变量的地址
}
```

## 模板（函数模板，类模板）

模板的定义：**函数模板不是一个实在的函数，编译器不能为其生成可执行代码。定义函数模板后只是一个对函数功能框架的描述，当它具体执行时，将根据传递的实际参数决定其功能。**

**函数模板**：交换两个整型数据与交换两个字符型数据，这两个函数的实现是类似的，只是输入类型不同，这时就可以用到函数模板。

```cpp
template <class T>
void Swap(T & x, T & y)
{
    T tmp = x;
    x = y;
    y = tmp;
}
```

上述是两个数据交换的函数，主函数调用方式如下：

```cpp
int n = 1, m = 2;
Swap(n, m);  //编译器自动生成 void Swap (int &, int &)函数
double f = 1.2, g = 2.3;
Swap(f, g);  //编译器自动生成 void Swap (double &, double &)函数
```

**类模板**：类模板与函数模板的定义和使用类似，我们已经进行了介绍。 有时，有两个或多个类，其功能是相同的，仅仅是数据类型不同

例：

```cpp
 1 //类的类型参数化 抽象的类
 2 //单个类模板
 3 template<typename T>
 4 class A 
 5 {
 6 public:
 7     A(T t)
 8     {
 9         this->t = t;
10     }
11 
12     T &getT()
13     {
14         return t;
15     }
16 protected:
17 public:
18     T t;
19 };
20 void main()
21 {
22    //模板类中如果使用了构造函数,则遵守以前的类的构造函数的调用规则
23     A<int>  a(100); 
24     a.getT();
25     printAA(a);
26     return ;
27 }
```





## 函数

函数的声明写在头文件，定义写在源文件（并非是在main函数文件中）

### 函数的参数列表可以有默认值

```cpp
int add(int a, int b = 10, int c = 20)
{
	return a + b + c;
}
int add(int a, int b = 10, int c);//错误，如果一个有默认参数，那么后边的都必须有
```

​	一个有默认参数，那么后边的都必须有

​	函数的声明和实现只能有一个有默认参数表

### 占位参数

```cpp
void func(int a, int); //占位参数
```

​	占位参数也可以有默认值

### 函数重载

* 函数名称相同，但是参数列表不相同（个数，顺序，类型），但是**返回值不同不能重载**

* 引用也可以作为参数列表进行函数重载，并且 **int& 和 const int& 就可以进行函数重载**

* 函数重载碰上默认参数出现二义性，应该尽量避免

  ```cpp
  int func(int a; int b = 10);
  int func(inta);
  
  func(10); //报错，两个函数都可以调用
  ```

  



## 指针

32位操作系统占4个字节，64位操作系统占8个字节。（不论是指向哪种数据类型都一样）

指针常量和常量指针（指针是常量，常量的指针）

### 空指针 

指向的地址为零 不可访问

### 野指针

 指向非法的地址空间，或者已经释放的地址空间

### 智能指针



## 引用

引用本质上是一个**指针常量**

```cpp
int a = 20;
int& b = a; //本质上是 int *const b = &a;
b = 100; //本质上解引用了 *b = 100;
```

### 引用与指针的区别：

* 引用声明和定义一起，指针可以先声明再定义
* 指针可以是空，引用不可以
* 指针可以改变，引用不可以(这就是指针常量啊，可以改变指向的值，但是不能改变指向)
* 指针是存的变量的地址，而引用本质上与原变量是同一个东西
* sizeof操作指针返回指针所占字节（均相同），操作引用返回原变量所占字节
* 当把指针作为**参数进行传递**时，也是将**实参的一个拷贝传递给形参**，**两者指向的地址相同**，但**不是同一个变量**，在函数中**改变这个变量的指向**不影响实参，而引用却可以（我的理解：指针传进去实际上就是烤了个地址，可以修改地址上的数据，但是修改这个地址本身，不会影响到实参）

函数的返回值是引用，则函数调用可以作为一个左值

```cpp
double &setValues(int i) //返回的是nums[i]的引用
{
    double &ref = nums[i];
    return ref;
}

setValues(1) = 20.23; // 改变第 2 个元素
setValues(3) = 70.8;  // 改变第 4 个元素
```

### 常量引用

修饰不想被改变的形参

```cpp
int &ref = 10; //错误 引用必须是引一块合法的内存空间
const int &ref = 10; //正确 ref不能被修改了
```



## 结构体（数据类型）

创建结构体变量

```cpp
StructName s1;//第一种
s1.name = "张三";
s1.age = 12;
s1.score = 24;

StructName s2 {"张三",12,24};//第二种

//直接在结构体定义时创建变量
struct student{
 	int age;
    string name;
    int score;
}s3;
```

### 结构体数组

```cpp
struct student{
 	int age;
    string name;
    int score;
};

int main(){
    student stuArray[3] = {
        {"zhangsan",12,23},
        {"lisi", 25, 36},
        {"wangwu", 25, 69}
    };
}
```

依然可以利用.运算符对结构体数组中的元素赋值

### 结构体指针

```cpp
student s = {"zhangsan", 12, 69};
student* s2 = &s;
```

使用->运算符访问结构体变量中的元素（s2->age其实就是*s2.age）

### 结构体嵌套结构体

```cpp
struct teacher{
 	int id;
    string name;
    int age;
    student std;
};
```

依旧使用.运算符访问和修改数据

思考：如何使用结构体简单的实现一个类

### 结构体作为参数列表

```cpp
void printStudent(student s1){
    cout<<s1.age;
}//拷贝开销较大，数据量大时不建议使用

void printStudent(student* s2){
    cout<<s2->age;
}//开销小，只有八个字节，但是会改变元素的值，
```

### 结构体中的const指针

地址做参数，可能会改变结构体元素的值

```cpp
void printStudent(const student* s2){
    cout<<s2->age;
}// 常量指针，不能更改指向的值了
```
## 类（class）

类的属性和方法声明一般放在头文件中，定义在cpp文件中放置（科大刘利刚老师的代码是这样写的）

+ 封装：把成员和方法抽象成一个类，安全灵活，
+ 继承：
+ 多态：

### 构造函数（constructor）

1. 一个类可以设置多个构造函数（函数重载，适应不同的初始化需求）

    ```cpp
    * Array();//默认构造函数
    * Array(int nSize, double dValue = 0);//带两个参数的构造函数，其中第二个参数有一个默认值
    ```

	创建类的对象实例时使用下列代码：

    ```cpp
    Array arr1; // 调用无参数的构造函数
    Array arr2(10, 5.0); // 调用带参数的构造函数
    Array arr3(5); // 也会调用带参数的构造函数，因为第二个参数有默认值
    ```

2. 构造函数还可以使用初始化列表来初始化字段，例：

    ```cpp
    Line::Line( double len): length(len)
    {
        cout << "Object is being created, length = " << len << endl;
    }
    ```

	上面的语法等同于：

    ```cpp
    Line::Line( double len)
    {
        length = len;
        cout << "Object is being created, length = " << len << endl;
    }
    ```

	也可以初始化多个字段：

    ```cpp
    C::C( double a, double b, double c): X(a), Y(b), Z(c)
    {
      ....
    }
    ```

	例如：在链表结构体的构建过程中

    ```cpp
    // 单链表
    struct ListNode {
        int val;  // 节点上存储的元素
        ListNode *next;  // 指向下一个节点的指针
        ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数，将x的值赋给val，next指针为空
    };
    
    int main()
    {
        ListNode* head = new ListNode(5)//使用自己的构造函函数初始化头结点
        ListNode* head = new ListNode()//使用默认构造函数初始化头结点
        head->val = 5;
    }
    ```
    
    **一般建议使用成员初始化列表对成员变量进行初始化，因为如果一个成员变量没有在初始化列表中被初始化，那么它将会被默认初始化**，参考下例：
    
    ```cpp
    class Example
    {
    public:
        Example(int x)
        {
            cout << "Example is " << x << endl;
        }
        Example()
        {
            cout << "Example is " << endl;
        }
    };
    
    class Entity
    {
    public:
        Example m_example;
    
        Entity() : m_example(Example(10))
        {
        }
    };
    
    int main()
    {
        Entity e; //使用类初始化列表，创建Entity对象e，输出Example is 10
    }
    ```
    
    如果不使用初始化构造列表：
    
    ```cpp
    class Entity
    {
    public:
        Example m_example;
    
        Entity()
        {
            m_example = Example(10);
        }
    };
    ```
    
    此时创建Entity对象e，输出：
    
    Example is 
    Example is 8
    
    原因，没有使用初始化列表对m_example进行初始化，则首先调用Example类的默认构造函数进行初始化，之后Entity类的构造函数又创建了一个m_example = Example(10)的对象，因此输出了两个对象

### 内联函数（inline）

1. 如果一个函数是内联的，编译时，会把该函数的代码副本放置在每个调用该函数的地方。而普通函数是在运行时调用

2. 类内的方法（函数）是默认内联的，但是编译器自身的优化可能不内联此函数（函数过于复杂的时候）

3. 强制内联加上inline关键字

4. 函数短小，并且用的多时使用内联。复杂的函数不要内联（适得其反）；递归函数不要使用内联

5. 声明方式：

    ```cpp
    inline return_type FunctionName(parameter list){};
    ```

	**优点：**避免压栈出栈，提高效率；减少函数调用开销；代码可读性增加（内联函数直接放在类声明中，方便理解和维护）

### 虚函数（virtual）

   代码示例：
```cpp
class Entity //基类
{
public:
	virtual string GetName() //基类中的GetName函数定义为虚函数
    {
        return "Entity";
    }
};
class Player : public Entity
{
private:
	string m_Name;
public:
	Player(const string &name) : m_Name(name) {}
	string GetName() override { return m_Name; } //重新定义GetName函数以实现多态
};
```

1. 在基类中使用virtual关键字声明函数，在派生类重新定义这个函数时，告诉编译器不要**静态链接**到基类中的该函数，以实现**多态**。

	* 目的：**在派生类中重新定义与基类同名的函数，可以通过基类指针或引用访问基类和派生类的同名函数**

2. 实现虚函数的步骤：

    ```cpp
    *定义基类，声明基类函数为virtual
    *定义派生类（继承自基类），派生类实现了定义在基类的virtual函数
    *声明基类指针，并指向派生类，调用virtual函数，此时虽然是基类指针，但调用了派生类实现的virtual函数
    ```

3. **纯虚函数**：在基类中定义的方法没有具体的实现，此时用到纯虚函数
	* 带有纯虚函数的类为抽象类，不能直接生成对象。
	* **优点**：防止派生类忘记实现虚函数，纯虚函数使得派生类必须实现基类的虚函数
    ```cpp
    virtual string eat() = 0; //在基类中，告诉编译器，函数没有主体。
    ```

	* 一般在cpp内定义接口（interface）时用到纯虚函数，cpp内的接口就是class，而其他语言有interface关键字
	
4. 虚函数的使用说明：

    * 在基类加上virtual关键字，在派生类重新定义时加上override，**来保证确实重新定义的函数原型与基类的函数原型（函数类型，函数名，参数个数，参数类型顺序）完全一样**

    * 派生类重新定义时可以不写关键字virtual，最好加上override保证正确性

    * 如果在派生类中没有重新定义虚函数，则**公有派生类继承基类的虚函数**

    * 虚函数不能是**友元函数**和**静态成员函数**

    * 使用**对象名和点运算符调用虚函数是在编译时进行**的，是静态编译，没有利用虚函数的特性。只有通过**父类指针访问子类中重写的虚函数**时才能获得运行时的多态性。（例如：Player *p = new Player() 这样定义的p指针是无法体现多态的）

    ```cpp
    Player p("zhou"); //定义一个派生类对象p
    Entity* e = &p; //定义一个基类指针e指向对象p
    cout << e->GetName() << endl; //访问虚函数（实际输出是派生类中的虚函数）
    ```

5. 虚析构函数

   一个类中如果有虚函数，则默认的析构函数也是虚函数，例如：

    ```cpp
    Entity* e = new Player();
    delete e;
    ```

   * 上述定义了一个指向派生类的基类指针，删除指针释放内存时，会首先调用派生类Player的析构函数，再调用基类Entity的析构函数。

   * 定义的类中有虚函数时，如果自己定义析构函数，一定要定义为虚析构函数。防止释放了基类的指针内存，而没有释放派生类的空间，造成内存泄漏。

6. 虚函数表（V-Table）

   由编译器生成，一个类有虚函数，就会生成一个四个字节的虚函数表指针，指向虚函数表。存储在对象实例最前面的位置。（虚函数表用来存放虚函数地址）

虚函数的一些缺点（运行时的花费）：

* 需要额外的内存去存储虚表；
* 调用虚函数时需要遍历虚表找到需要运行的函数

*我对虚函数的一些理解*：想要根据特定的对象选择函数的实现功能（但是函数名和基类相同（为了更好地适用于对象，比如：对于基类是一个动物类，派生类猫类，都有“吃”这个方法（函数），但是我想在猫类中指定“吃鱼”这个方法，但是方法名仍然设为“吃”，这时候就需要虚函数））称为**动态链接**。

> 相应的还有鸭子模板类型，可以不利用虚函数，已达到多态，这里还没学。

### c++中的访问修饰符

private:只有当前类可以访问到private函数，类的对象也无法访问（注：但是友元是可以访问的）

protect：可见性略高于private，但低于public。与private的区别是，protect的属性和方法在派生类中可以访问

public：所有地方都可以访问

1. class默认private、struct默认public
2. 访问修饰符是人设计出来的，与cpu和电脑是无关的，就是规定了对类中成员的访问限制
3. 确保不会调用一些不应该调用的代码，造成破坏
4. 增强代码可读性（这在大项目中是很重要的）

### 如何实例化一个类？

```cpp
Entity e; //栈上创建一个类
e.Get(); //调用成员函数

Entity *e1 = new Entity(); //堆上创建
(*e1).Get(); //调用成员函数，首先要解引用，也可以使用e1->Get()

delete e; //不用了就释放掉
```

* 可以在堆区或者栈区实例化，栈区特点是，其生命周期是由作用域决定的，一旦超过了作用域，栈区申请的内存就会被释放掉（栈弹出）

*  堆去很大，堆上创建的变量的生命周期一直持续到程序结束，也可以使用delete语句释放掉内存，使用完毕要释放内存，否则可能导致之后申请堆内存时出问题（内存泄漏）

* 堆的申请比栈时间要长。如果类的**对象非常大或者想要大的生命周期**，那就在堆中创建；否则在栈上创建（自动回收内存真的很Cool的好吧！！！！）

### this指针

代码不存在二义性隐患时，不必使用




