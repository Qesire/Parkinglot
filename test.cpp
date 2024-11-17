#include"ZCcarF.h"

using namespace std;
int main()
{
	int n, m, p;
	printf("请输入停车场最大容量：");
	cin >> n;
	printf("请输入候车道最大容量：");
	cin >> m;
	printf("请输入停车价格：");
	cin >> p;
	rewind(stdin);

	ParkingStack s;
	WaitingQueue q;
	initParkingStack(s, n);
	initWaitingQueue(q, m);

	//接收输入指令
	while (1)
	{
		char task;
		int number, time;
		cout<<"输入指令："<<endl;
		scanf("%c%d%d", &task, &number, &time);
		rewind(stdin);
		if (task == 'A' || task == 'a')
		{//到达
			CarIn(s, q, number, time);
		}
		else if (task == 'D' || task == 'd')
		{//离开
			CarOut(s, q, number, time, n, p);
		}
		else if (task == 'P' || task == 'p')
		{//显示停车场的车
			CheckParking(s);
		}
		else if (task == 'W' || task == 'w')
		{//显示候车场的车
			CheckWaiting(q);
		}
		else if (task == 'E' || task == 'e')
		{//退出程序
			deleteParkingStack(s);
			deleteWaitingQueue(q);
			cout<<"即将退出程序"<<endl;
			break;
		}
		else
		{
			cout<<"非法操作：无法识别的指令!"<<endl;
		}
	}
	return 0;
}