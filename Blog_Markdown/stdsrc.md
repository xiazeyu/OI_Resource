## 头文件
```cpp
#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define OJ

using namespace std;

inline int qmin(int a, int b){ // 位运算加速的求较小数 - 返回值 较小数 
	int diff = b - a;
	// b < a : a + (diff & -1)
	// b > a : a + (diff & 0)
	return a + (diff & (diff >> 31));
}
inline int qmax(int a, int b){ // 位运算加速的求较大数 - 返回值 较大数 
	int diff = b - a;
	// b < a : b - (diff & -1)
	// b > a : b - (diff & 0)
	return b - (diff & (diff >> 31));
}
inline int qabs(int a){ // 位运算加速的绝对值  - 返回值 绝对值 
	int t = (a >> 31);
	return (a + t) ^ t;
}
inline bool isOdd(int a){ // 判断奇偶性 - 返回 1 是奇数; 返回 0 是偶数 
	return a & 1 == 1;
}
inline void qswap(int* a, int* b){ // 位运算加速的快速交换 - 用法 qswap(&a, &b);
	(*a) ^= (*b) ^= (*a) ^= (*b);
	return;
}
inline int qread(){ // 快速读入int - 返回 读入的数 
	char c = getchar();
	int f = 1, x = 0;
	while(!isdigit(c)){if(c == '-') f= -1; c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0'; c = getchar();}
	return f * x;
}

int main(){
	#ifndef OJ
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	
	
	
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
	
}

```

## 说明
- 12行 关于inline内联函数的使用：
  inline的作用是替代C语言中define的。
  [inline [百度百科]](https://baike.baidu.com/item/inline/10566989?fr=aladdin "inline 百度百科")：define**不能进行参数有效性的检测**，也就**不能享受C++编译器严格类型检查的好处**，另外它的**返回值也不能被强制转换为可转换的合适的类型**而且存在**二义性问题**

- 12行 关于位运算max&min&abs 
[位运算实现int的abs/min/max函数 [CSDN]](http://blog.csdn.net/chaosllgao/article/details/6185319 "位运算实现int的abs/min/max函数 [CSDN]")

- 12行 关于C++常用位运算
[C/C++位运算技巧 [CSDN]](http://blog.csdn.net/zouliping123/article/details/8995373 "C/C++位运算技巧 [CSDN]")

- 45行 关于文件操作
[LoveYayoi的std_src.cpp源码 [GitHub]](https://github.com/LoveYayoi/OI-Package/blob/master/DS%26Algorithm-Models/%E7%BC%BA%E7%9C%81%E6%BA%90%E4%B8%80%E7%B1%BB/std_src.cpp "LoveYayoi的std_src.cpp源码 [GitHub]") 网上其他教程实在是太坑爹了
C的文件操作 [C语言中输入输出重定，freopen()妙用。 [ChinaUnix]](http://blog.chinaunix.net/uid-11600035-id-2866019.html "C语言中输入输出重定，freopen()妙用。 [ChinaUnix]")
判断是否度入到文件尾
```cpp
	string t;
	while(!feof(stdin)){
		cin>>t;
		cout<<t<<endl;
	}
```

- 35行 关于快速读入
[快速读入 [CSDN]](http://blog.csdn.net/WhiStLenA/article/details/51712580 "快速读入 [CSDN]")
[如何看待在OI/ACM赛事广为使用的快速读入整数？ [ZhiHu]](https://www.zhihu.com/question/49059234 "如何看待在OI/ACM赛事广为使用的快速读入整数？ [ZhiHu]")

- 读入string/char之类的最好直接cin、cout，**千万不要自己判"\n"**免得莫名被卡

- 好文章之ACM常用工具函数整理
[[ACM]常用工具函数整理 [CSDN]](http://blog.csdn.net/sr_19930829/article/details/46048571 "[ACM]常用工具函数整理 [CSDN]")
