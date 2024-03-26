/*------------------------------------------------------------------------------
 * @file    LEARNSTATIC.CPP
 * @author  ZhouRongTao 
 * @date    2023/11/22 09:27:54
------------------------------------------------------------------------------*/
#include <iostream>

void Function() //�ֲ������;ֲ���̬�������������������������𡣲���ע�⣺�ֲ�����û�����ó�ֵ����������ʱ�Ѿ��Զ���ʼ��Ϊ0��
{
	int i = 0;
	static int s_i;
	i++;
	s_i++;
	std::cout << "i = " << i << " ";
	std::cout << "s_i = " << s_i << std::endl;
}

int main()
{
	Function();
	Function();
	Function();
	Function();
	Function();
	std::cin.get();
}