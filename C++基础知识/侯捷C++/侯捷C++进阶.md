Class

## Complex类

* 不带指针的类（complex）
* 带指针的类（string）

### 头文件与类的声明

* .h 类的声明
* .cpp main()函数 
* 标准库的.h
* 类成员设为私有（private）

### 构造函数

* 使用构造函数初始化列表初始化对象，效率高。普通的赋值是先初始化再赋值
* 不带指针的类多半是不用写析构函数的
* 构造函数的重载（overloading）
* ![image-20240318142256446](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240318142256446.png)这是不能重载的，因为第一个有默认参数了

### 函数传递与返回值

* 构造函数放在private中，单例模式![image-20240318142448060](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240318142448060.png)
* 函数后加const，表示不能改变类内成员
* const的对象，调用成员函数时一定要确保此函数是const的，否则会报错 
* **参数传递**：by value vs by reference **尽量传引用**（或者const引用）
* **返回值传递：**尽量用reference传递。但是如果函数要**创建一个内存地址来放结果**（例如存两个复数相加的结果），就不能return这个引用，因为函数作用域结束就被释放了，这时候传值或者传指针。
* friend友元：可以访问到对象的成员。（按照封装的目的，应该是friend越少越好）
* **相同的class的各个对象是互为friend（友元的），第一个对象可以直接访问到第二个对象的私有成员**

### 操作符重载与临时对象

* 成员函数一定有一个隐藏参数this指针
* += 操作符重载要返回引用，这样可以连续+=，比如c1+=c2+=c3

## String类

* **有指针的类，一定要有拷贝构造和拷贝赋值函数**

<img src="C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240322130915845.png" alt="image-20240322130915845" style="zoom: 50%;" />

上面是深拷贝，下面是浅拷贝。b = a,我们是想重新建一块地址存hello，再用指针指向，而浅拷贝直接把指针指向原来的hello

* 拷贝赋值：

![image-20240322131621978](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240322131621978.png)

一定要写if里面的那一块，否则如果this和str指向同一块内存，直接deletem_data了，str同样也没了，拷贝赋值就会出错。

### output函数

同样要写为全局函数，符合cout的通常形式



### 构造函数与析构函数

new之后在析构函数时一定要delete，否则造成内存泄漏

虚数的实现中，不用delete，因为被操作系统直接杀死了

```cpp
ostream& operator << (ostream& os, const complex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}
```

如果写为成员函数，会怎样？

```cpp
a << cout //就得这样调用了，思考成员函数的this指针
```

### new和delete

new：先分配空间（memory），再调用构造函数

new的具体实现：

```cpp
complex* pc = new complex(1, 2);
//编译器转化为：
void* men = operator new(sizeof(complex)); //申请内存，两个double类型的数据（8字节）
pc = static_cast<complex*>(men); //转型（强制转换）
pc->complex::complex(1,2); //构造函数
```

![image-20240322133453459](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240322133453459.png)

delete的具体实现：先调用析构函数，再释放内存

```cpp
String* ps = new String("hello");
delete ps;
//实现如下：
String::~String(ps);
operator delete(ps);//内部调用free(ps)
```

![image-20240322133959641](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240322133959641.png)



array new 一定要搭配 array delete

![image-20240322140411044](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240322140411044.png)

要让编译器知道，我构造了一个string对象的数组，要调用三次析构函数，然后释放空间（这一步其实不需要[]，因为内存上已经存着申请了多少空间）加[]的目的是让编译器知道调用几次虚构函数。

如果new了一个complex对象的数组，只是开辟了几个double的空间，释放内存直接杀掉就可以了，加不加[]都无所谓，但是一般为了规范化，最好加上



## 类模板、函数模板、及其他

### static

* 静态成员
* 静态函数

成员函数是有默认的this指针的，

```cpp
double real() const
{
    return this->real; //this->可以不写，编译器会默认加上
}
```

static关键字：

* static数据成员：所有类对象共有的。类内声明，类外定义
* static成员函数：只能处理静态的数据(没有this指针)。通过**类名**或者**类对象调用**

上述static例子用银行开户利率作为引理

### 单例模式

把构造函数放在private中（单例模式）

![image-20240323142941595](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240323142941595.png)

始终存在一个且只有一个对象

![image-20240323143125888](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240323143125888.png)

只有调用的时候才会产生一个对象

### cout

cout是ostream的一个对象，<<的操作符重载

### 类模板

```cpp
template <typename T> //模板
class conplex
{
    ...//里面有T
}
complex<double> c1(2.5,1.5);//将上面的T全改为double创建一个类
```

### 函数模板

### 命名空间 namespace



## 组合与继承

### composition（复合） Adapter

![image-20240318134200397](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240318134200397.png)

在一个类中有另一个类的对象

* 复合关系下的构造与析构

![image-20240318133505627](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240318133505627.png)



* Container的构造函数由内而外，先调用Component的default构造函数，再执行自己的

* Container的析构函数由外而内，先执行自己的析构函数，再调用Component的析构函数

### Delegation（委托）Composition by reference

（即使用指针传也是叫by reference）

![image-20240318133952613](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240318133952613.png)

在一个类中有指向另一个类的指针（pimpl，非常有名类实现方式）（编译防火墙）

### inheritance(继承)

![image-20240324132149630](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324132149630.png)

和虚函数搭配才能最体现继承的特点

![image-20240324132350407](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324132350407.png)

子类里面有父类的成分

* 构造由内而外，先调父类，再调子类
* 析构由外而内，先析构子类，再析构父类

#### inheritance with virtual function

data继承，成员函数继承调用权

* non-virtual函数:不希望子类重新定义（override）

* virtual函数：子类可以重新定义，但是已有默认定义
* pure-virtual函数：子类一定要重新定义



![image-20240324133310141](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324133310141.png)



#### inheritance + composition下的构造和析构



![image-20240324134655807](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324134655807.png)

构造函数先基类，再component，再派生类，析构函数反之

![image-20240324134711838](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324134711838.png)

#### delegation + inheritance 委托加继承

































# C++高级开发下

## reference 引用

* reference虽然底部是指针实现的，但是对引用的任何操作与对原对象操作结果都一样，例如：

```cpp
int& a = b;
sizeof(a);
sizeof(b); //两者结果相同
```

* reference常用于**参数类型**和**返回参数类型**的描述，不常用于声明变量

* reference**底部是传指针**，如果传的对象较大，传引用很快

* 引用不能作为函数签名进行函数重载：

```cpp
int imag(int& a);
int imag(int a);//错误
//mian函数...
imag(a) //错误，不知道调用哪个
```

只有成员函数声明为const函数，全局函数声明没有意义，const函数可以重载，const函数只能由const对象调用



## object model

### inheritance + composition下的构造和析构

![image-20240324134655807](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240324134655807.png)

构造函数先基类，再component，再派生类，析构函数反之

### 虚函数和虚表（多态）

![image-20240326170210372](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240326170210372.png)

静态绑定：call xxx（地址）

动态绑定：指针调用，指针向上转型（up_cast），虚函数。（虚机制）

* 虚函数表在**编译时生成**，存在代码段，虚函数表指针在**构造函数初始化列表**时生成
* 指向派生类对象的基类指针无法访问派生类的非虚成员函数，使用虚函数就实现了一个接口多种方法
* 多继承下，会有多个虚函数表，派生类新增的虚函数默认放在最左侧的虚函数表中
* 派生类没有重写虚函数，则使用最新的虚函数版本（派生链的上一个类）

![image-20240327110903701](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240327110903701.png)

### 动态绑定

## const

* const关键字应该是写类的时候就确定这个方法要不要加，而不是事后加上的，比如打印函数print，从逻辑上来讲，打印不会改变数据成员，那他应该就是const函数

* 限定成员函数，不能是全局函数

* 函数可以将const作为签名，以进行函数重载

* **const对象只能调用const函数，非const对象可以调用const和非const函数，**但是**当成员函数const和non-const版本同时存在**时，const对象只能调用const版本，非const对象只能调用非const版本

## operator new、operator delete、operator new[]、operator delete[]重载

上面的四个函数是可以进行重载的，

![image-20240327170822295](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240327170822295.png)

![image-20240327170942637](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240327170942637.png)

p指向的堆内存，首先有一个counter计数器，存储这个数组有Foo的对象的个数，然后是5个foo对象



# C++标准库（体系结构与内核分析）

C++标准库大于stl

* C++标准库的头文件不带.h 例如#include<vector>
* 新式C头文件不带.h 例如#include<csdio>
* 旧式C头文件带.h 例如 #include<stdio.h>
* 新式的组件均在命名空间std中，旧式没有

## stl体系结构

stl六大部件：容器，分配器，算法，迭代器，适配器，仿函数

![image-20240330112059269](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240330112059269.png)

## 容器分类

* 关联式容器：set/Multiset、map/Multimap。红黑树实现。multi：元素内容可以重复

![image-20240330171947202](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240330171947202.png)

* 序列式容器：array（连续数组，定长）、vector、deque、list

![image-20240330145518124](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240330145518124.png)

Undered Containers：unordered set、unordered map 

<img src="C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240330172030050.png" alt="image-20240330172030050" style="zoom:50%;" />散列表独立链接

## 容器测试

* array：长度固定的数组，达到尾部无法再添加元素

* vector：长度未定，可以一直push_back，但是如果频繁的push_back，会导致稳定性下降，因为存放vector的内存可以已经存不下下一个push_back的元素，这时候就会复制整个数组到另一块内存中。vector扩展内存是两倍增长的；本身没有find函数

  ```cpp
  vec.capacity(); //真正所占内存，vector的内存两倍增长
  ```

* list：双向链表（有自己的sort函数）

* slist：单向链表 forward_list

* deque：双端队列，分段连续（buffer），要用到指针

* stack：不管是stack还是queue，都是从deque继承来的，底层实现都是deque，这些是没有iterator迭代器的，否则就会破坏这些结构的特性（先进先出、先进后出）

  <img src="C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240407105540215.png" alt="image-20240407105540215" style="zoom:50%;" />

* multiset：底层实现红黑树；本身就有find函数；重复的元素也可以放进去；不能用[]进行索引

* multimap：底层实现红黑树；不能用[]进行索引，可能有重复的key；

* unordered_multiset：底层实现hash表；不能用[]进行索引

* unordered_multimap：底层实现hash表；不能用[]进行索引

关联式容器：查找很快

* set：没有重复的元素
* map：key是不会重复的，可以用[]进行索引
* unordered_set：
* 

## 一些算法

* find函数：find(vec.begin(),vec.end(),target);（vector，array，list等序列性容器，只能调用全局的find函数）；set，map，multimap等关联式容器是用自己本身的find()，很快。
* sort();

## 分配器(allocator)

实际上就是分配内存，都要调用malloc()函数，实际上根据操作系统的不同，拿到不同的内存

不建议使用，**配器进行空间释放时，会要求程序员确定需要释放多少内存**。

## 源代码的分布（VC，GCC）

OOP：面向对象编程，data和method放在一起

GP：泛型编程，将data和method分开，

标准库的sort函数需要一定的条件，比如需要连续的迭代器，这是list链表数据结构所没有的

### 模版

* 函数模版，编译器可以进行实参推导
* 类模板，必须指定的模版T是什么，没有线索可以确定使用的是哪一个

1. 模板特化：

   ![image-20240407151210222](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240407151210222.png)

2. 模版偏特化：指定其中某个模版

   ![image-20240407151953067](C:\Users\18143\AppData\Roaming\Typora\typora-user-images\image-20240407151953067.png)

