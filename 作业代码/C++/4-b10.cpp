/*2151294 信11 马威*/
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：求num是不是base的幂
     输入参数：
     返 回 值：0 - 不是
               1 - 是
     说    明：函数名、形参、返回类型均不准动
   ***************************************************************************/
int is_power(int num, int base)
{
    /*1、num大于base的情况*/
    if (num > base) {

        /*1.1、若num大于base的平方（小于base的三次方），用浮点数j=num/base指示num与base之间的关系*/
        if (num / base == base) {
            float j = float(num) / float(base);

            /*若j与base接近（精度以内相等），直接判定此时num是base的平方，返回1*/
            if (j - base<1e-6f && j - base>-1e-6f) {
                return 1;
            }

            /*若j与base相差大（精度以内不等），直接判定此时num介于base的平方与base的三次方之间，返回0*/
            else {
                return 0;
            }
        }

        /*1.2、若num大于base（小于base的平方），直接判定此时num介于base与base的平方之间，返回0*/
        else if (num / base == 1) {
            return 0;
        }

        /*1.3、若num大于base的三次方，递归调用is_power()，使num=num/base*/
        else {
            return is_power(num / base, base);
        }
    }

    /*2、num大于base的情况*/
    else if (num < base) {

        /*2.1、若num=1，直接判定此时num是base的0次方，返回1*/
        if (num == 1) {
            return 1;
        }

        /*2.2、若num不为1，直接判定此时num介于base的0次方与base之间，返回0*/
        else {
            return 0;
        }
    }

    /*3.num等于base的情况，直接判定此时num是base的一次方，返回1*/
    else {
        return 1;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入、调用递归函数、输出
***************************************************************************/
int main()
{
    int ret, num, base;
    cout << "请输入整数num及基数base" << endl;
    cin >> num >> base;         /*完成输入*/
    ret = is_power(num, base);  /*调用递归函数*/

    /*输出*/
    if (ret == 1) {
        cout << num << "是" << base << "的幂" << endl;
    }

    else if (ret == 0) {
        cout << num << "不是" << base << "的幂" << endl;
    }

    return 0;
}