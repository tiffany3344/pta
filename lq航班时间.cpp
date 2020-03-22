/*
标题：航班时间

【问题背景】
小h前往美国参加了蓝桥杯国际赛。小h的女朋友发现小h上午十点出发，上午十二点到达美国，于是感叹到“现在飞机飞得真快，两小时就能到美国了”。

小h对超音速飞行感到十分恐惧。仔细观察后发现飞机的起降时间都是当地时间。由于北京和美国东部有12小时时差，故飞机总共需要14小时的飞行时间。

不久后小h的女朋友去中东交换。小h并不知道中东与北京的时差。但是小h得到了女朋友来回航班的起降时间。小h想知道女朋友的航班飞行时间是多少。

【问题描述】
对于一个可能跨时区的航班，给定来回程的起降时间。假设飞机来回飞行时间相同，求飞机的飞行时间。

【输入格式】
从标准输入读入数据。
一个输入包含多组数据。

输入第一行为一个正整数T，表示输入数据组数。
每组数据包含两行，第一行为去程的 起降 时间，第二行为回程的 起降 时间。
起降时间的格式如下

h1:m1:s1 h2:m2:s2
或
h1:m1:s1 h3:m3:s3 (+1)
或
h1:m1:s1 h4:m4:s4 (+2)
表示该航班在当地时间h1时m1分s1秒起飞，

第一种格式表示在当地时间 当日 h2时m2分s2秒降落
第二种格式表示在当地时间 次日 h3时m3分s3秒降落。
第三种格式表示在当地时间 第三天 h4时m4分s4秒降落。

对于此题目中的所有以 h:m:s 形式给出的时间, 保证 ( 0<=h<=23, 0<=m,s<=59 ).

【输出格式】
输出到标准输出。

对于每一组数据输出一行一个时间hh:mm:ss，表示飞行时间为hh小时mm分ss秒。
注意，当时间为一位数时，要补齐前导零。如三小时四分五秒应写为03:04:05。

【样例输入】
3
17:48:19 21:57:24
11:05:18 15:14:23
17:21:07 00:31:46 (+1)
23:02:41 16:13:20 (+1)
10:19:19 20:41:24
22:19:04 16:41:09 (+1)

【样例输出】
04:09:05
12:10:39
14:22:05

题目本身非常简单，但是在输入的时候我却陷入了难题，最后看队友题解才发现了sscanf()函数，多学习吧

sscanf()函数同scanf()函数差别不大，不过一个是从键盘中读入，另一个从字符串里读入，其返回值也同scanf()一样，返回成功读入参数的个数

str.c_str()函数则是返回指向正规C字符串的指针常量, 内容与本string串相同
*/

#include <iostream>
#include <cstring>
using namespace std;
int time(string);
void print(int);
int main()
{
    string str;
    int T;
    cin>>T;
    getchar();
    int sum1,sum2;
    while(T--) {
        getline(cin,str);
        sum1 = time(str);
        getline(cin,str);
        sum2 = time(str);
        sum2 += sum1;
        sum2 /= 2;
        print(sum2);
    }
    return 0;
}
int time(string str)
{
    int h1,m1,s1,h2,m2,s2,day;
    day = 0;
    sscanf(str.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&day);
//    cout<<h1<<" "<<m1<<" "<<s1<<" "<<h2<<" "<<m2<<" "<<s2<<" "<<day<<endl;
    int count1,count2;
    count1 = h1*3600 + m1*60 + s1;
    count2 = h2*3600 + m2*60 +s2 + 24*3600*day;
    //Inorder to save memory,so I decide to put result on count2,h2,m2,s2.
    count2 = count2 - count1;
    return count2;
}
void print(int count2){
    int h2,m2;
    h2 = count2 / 3600;
    count2 = count2 % 3600;
    m2 = count2 / 60;
    // count2 == s2 ,I don't assign s2 with value of count2.
    count2 = count2%60;
    printf("%02d:%02d:%02d\n",h2,m2,count2);
}