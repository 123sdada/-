/**************************************
*	��Ŀ����:MyLove
*	��Ŀ����:������׳���
*	��Ŀ����:Vs2013 & EasyX
*	��������:2019-03-18
*	����:	�����(3118519083)
***************************************/
#include "graphics.h"//c++ͼ�ν����
#include "stdio.h"
#include "time.h"
#include "mmsystem.h"//��ý����Ƶ�ӿ�
#pragma comment(lib,"winmm.lib")//��ý�����־�̬��
struct Point {
	int x; //��ʾ���x����
	int y; //���y����
};

IMAGE img[10], //�洢10��ͼƬ  ���ͱ�����IMAGEͼƬ����
img_Big[10];  //����ͼƬ
//��ʼ�����ض���ͼƬ
void InitImg() 
{

	char buf[128] = { 0 };//���ͼƬ��·��
	for (int i = 0; i < 10; i++)//��������ÿ��ͼƬ
	{
		//��ʽת��  i:0-9 +1  1-10
		sprintf(buf, "ͼƬ//00%d.jpg", i + 1);
		//����ͼƬ�洢��img������
		//�����ַ����ĳ���
		int T_sizey = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
		//����һ�����ֽڵ��ַ�������
		TCHAR* stry = new TCHAR[sizeof(wchar_t) * T_sizey];
		MultiByteToWideChar(CP_ACP, 0, buf, -1, stry, T_sizey);
		//������������stringתΪtchar�ķ���

		loadimage(&img[i], stry, 40, 40);//�������ֲ���ͼƬ�Ŀ������ͼƬ�Ĵ�С
		loadimage(&img_Big[i], stry, 300, 200);//�м�Ĵ�ͼƬ
	}
}

int main() {


	//��������
	//�������� �� �� �ĵ�λ:px-> ����
	//GetSystemMetrics(SM_CXSCREEN)��ȡ��ǰ��Ļ�Ŀ�
	//GetSystemMetrics(SM_CYSCREEN)��ȡ��ǰ��Ļ�ĸ�
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));


	//���ô��ڷ��  ȥ�����⣨WS_CAPTION���⣩
	// GetWindowLong��ȡ ������ʽ
	//GWL_STYLE�����ڵ�һ����ʽ
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);

	//���ô���λ��
	//����ָ�����ڵ�ָ���ര��λ�ýṹHWND_TOPMOST
	SetWindowPos(hwnd, HWND_TOPMOST, 250,0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);// SWP_SHOWWINDOW��ʾ����

	//����Ϊ͸�� 
	// GWL_EXSTYLEһ�ַ��
	LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	//���ô��ڷ��
	SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);
	//�����޸�Ϊ��ɫ
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
	//��λ  ����״���ܱߵĵ�  Χ��һ�����ĵ�
	Point arr[46] = {
		{ 395, 268 },//��һ����λ��
		{ 406, 222 },
		{ 416, 193 },
		{ 441, 162 },
		{ 468, 133 },
		{ 500, 117 },
		{ 537, 105 },
		{ 577, 107 },
		{ 617, 120 },
		{ 649, 146 },
		{ 666, 173 },
		{ 680, 211 },
		{ 683, 247 },
		{ 680, 293 },
		{ 675, 338 },
		{ 660, 385 },
		{ 640, 440 },
		{ 616, 484 },
		{ 588, 529 },
		{ 557, 573 },
		{ 530, 610 },
		{ 493, 645 },
		{ 460, 675 },
		{ 422, 696 },
		{ 381, 676 },
		{ 350, 654 },
		{ 320, 626 },
		{ 292, 606 },
		{ 257, 570 },
		{ 230, 540 },
		{ 200, 500 },
		{ 180, 470 },
		{ 160, 430 },
		{ 140, 390 },
		{ 126, 342 },
		{ 117, 293 },
		{ 120, 250 },
		{ 133, 203 },
		{ 160, 170 },
		{ 200, 140 },
		{ 240, 130 },
		{ 280, 135 },
		{ 312, 146 },
		{ 340, 170 },
		{ 360, 195 },
		{ 375, 230 }
	};
	//���س�ʼ��ͼƬ
	InitImg();

	//���
	wchar_t buff[46][50] = {
		L"�������������",
		L"����ݵ�",
		L"������Զ��",
		L"�¿���������",
		L"������û��",
		L"�����������",
		L"����",
		L"����������",
		L"������",
		L"��ʱ�򻹲�������",
		L"�����",
		L"�ž���",
		L"�̹�����",
		L"Ϊʲô",
		L"û�з���",
		L"��������",
		L"������",
		L"��õ�����",
		L"Ҳ��ʱ",
		L"æ��΢Ц�Ϳ���",
		L"æ��׷��",
		L"����е�����",
		L"��������Ȼ",
		L"������",
		L"��˭��������",
		L"һֱĬĬ�ػ�",
		L"��ԭ��",
		L"ԭ��������",
		L"������ס������",
		L"ԭ������",
		L"�Ͱ�������������ô��",
		L"��Ϊ��",
		L"�Կ�����ľ���",
		L"������",
		L"�ܵ���",
		L"һĻĻ������",
		L"һ����Ⱦ������",
		L"��������",
		L"������",
		L"������ʧȥ",
		L"Ϊ����������",
		L"��Ȩ��",
		L"��Ը��",
		L"�ҿ�",
		L"����",
		L"�����"
	};

	//ͨ��ʱ���������������
	srand((unsigned)time(NULL));

	//1.�����ǵ���Ƶ�ļ� open x.mp3
	mciSendString(_T("open ����//xxx.mp3"), 0, 0, 0);
	////2.������Ƶ�ļ�  play x.mp3
	mciSendString(_T("play ����//xxx.mp3"), 0, 0, 0);

	//�����  /**/
	//forѭ��������ʾ46�����ӡͼƬ
	for (int i = 0; i < 46; i++) {

		//�����ı���ɫ  settextcolor
		//��ɫ��ǳ��Χ0-255     rand%256 ���������ɫ��ΧΪ0-255
		settextcolor(/*RGB(rand() % 256, rand() % 256, rand() % 256)*/RGB(94, 10, 36));
		//��ӡͼƬ����46��ͼƬ����ÿһ��ͼƬ��x��yֵ
		putimage(arr[i].x, arr[i].y, &img[i % 10]);

		//��ӡ����
		outtextxy(arr[i].x, arr[i].y, buff[i]);

		Sleep(80);
	}

	//MOUSEMSG m;

	int add = 0;

	while (1)//��ͼƬ��ͣ����������ڴ�ӡ����
	{
		//����豸������
		cleardevice();
		for (int i = 0; i < 46; i++) {
			//�����ı���ɫ  settextcolor
			//settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			putimage(arr[i].x, arr[i].y, &img[(i + add) % 10]);
			outtextxy(arr[i].x, arr[i].y, buff[(i+add)%46]);
		}
	//���ͼƬ
		putimage(274, 311, &img_Big[add % 10]);
		add++;
		Sleep(1000);
	}

	system("pause");
	closegraph();
	return 0;
}