#include"ZCcarF.h"

using namespace std;
int main()
{
	int n, m, p;
	printf("������ͣ�������������");
	cin >> n;
	printf("������򳵵����������");
	cin >> m;
	printf("������ͣ���۸�");
	cin >> p;
	rewind(stdin);

	ParkingStack s;
	WaitingQueue q;
	initParkingStack(s, n);
	initWaitingQueue(q, m);

	//��������ָ��
	while (1)
	{
		char task;
		int number, time;
		cout<<"����ָ�"<<endl;
		scanf("%c%d%d", &task, &number, &time);
		rewind(stdin);
		if (task == 'A' || task == 'a')
		{//����
			CarIn(s, q, number, time);
		}
		else if (task == 'D' || task == 'd')
		{//�뿪
			CarOut(s, q, number, time, n, p);
		}
		else if (task == 'P' || task == 'p')
		{//��ʾͣ�����ĳ�
			CheckParking(s);
		}
		else if (task == 'W' || task == 'w')
		{//��ʾ�򳵳��ĳ�
			CheckWaiting(q);
		}
		else if (task == 'E' || task == 'e')
		{//�˳�����
			deleteParkingStack(s);
			deleteWaitingQueue(q);
			cout<<"�����˳�����"<<endl;
			break;
		}
		else
		{
			cout<<"�Ƿ��������޷�ʶ���ָ��!"<<endl;
		}
	}
	return 0;
}