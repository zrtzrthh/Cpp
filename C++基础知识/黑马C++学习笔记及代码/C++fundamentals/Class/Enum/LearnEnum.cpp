/*------------------------------------------------------------------------------
 * @file    LEARNENUM.CPP
 * @author  ZhouRongTao
 * @date    2023/11/23 11:41:39
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

enum enumType
{
    Monday,
    Tuesday,
    Wedesday,
    Thursday,
    Frday,
    Saturday,
}; // Ĭ����0-6�����ǿ�����ʽ�����ã�Monday = 1, Tuesday = 2, Wedesday = 3, Thursday, Frday, Saturday,δ��ʼ����ö��ֵĬ�ϱ�ǰһ����1

int main()
{
    enumType Weekday;

    // ֻ�ܽ������ö������������ö�ٵı��������ܽ�����ֵ����ö�ٱ���������Weekday = 10�ǷǷ���
    Weekday = Monday;

    // ���ǿ��Խ�ö����������ö�ٱ������������Զ���ö����ת��Ϊint��
    int a = Monday;

    // ö�ٱ���û���������㣬��Weekday = Monday + Tuesday; Weekday++ �ǷǷ��ģ�ö����ֻ�и�ֵ���㡣

    // ö�������Բ����������ͱ��������㣬�������Զ���ö����ת��Ϊint��
    a = 1 + Monday;

    // ����ͨ��ǿ������ת�������������͸�ֵ��ö�ٱ������ȼ���Weekday = Wednesday�����Ƕ���Weekday = enumType(20)������ǲ�ȷ���ģ�һ�㲻������ô��
    // ö��ȡֵ��Χ��ö������Ϊ���ö��������С2���ݼ�һ��ö�����ޣ�����Сֵ��С��0������ȡ0������СֵС��0��ö��������С����Сö����������2���ݼ�һ

    Weekday = enumType(100);
    cout << Weekday << endl;
    Weekday = enumType(2);
}