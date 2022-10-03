/**************************************
*	项目名称:MyLove
*	项目描述:制作表白程序
*	项目环境:Vs2013 & EasyX
*	生成日期:2019-03-18
*	作者:	龙卷风(3118519083)
***************************************/
#include "graphics.h"//c++图形界面库
#include "stdio.h"
#include "time.h"
#include "mmsystem.h"//多媒体音频接口
#pragma comment(lib,"winmm.lib")//多媒体音乐静态库
struct Point {
	int x; //表示点的x坐标
	int y; //点的y坐标
};

IMAGE img[10], //存储10张图片  类型必须是IMAGE图片类型
img_Big[10];  //加载图片
//初始化加载多张图片
void InitImg() 
{

	char buf[128] = { 0 };//存放图片的路径
	for (int i = 0; i < 10; i++)//遍历加载每张图片
	{
		//格式转换  i:0-9 +1  1-10
		sprintf(buf, "图片//00%d.jpg", i + 1);
		//加载图片存储在img数组中
		//返回字符串的长度
		int T_sizey = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
		//申请一个多字节的字符串变量
		TCHAR* stry = new TCHAR[sizeof(wchar_t) * T_sizey];
		MultiByteToWideChar(CP_ACP, 0, buf, -1, stry, T_sizey);
		//以上这三行是string转为tchar的方法

		loadimage(&img[i], stry, 40, 40);//后面数字参数图片的宽高设置图片的大小
		loadimage(&img_Big[i], stry, 300, 200);//中间的大图片
	}
}

int main() {


	//创建窗口
	//创建窗口 宽 高 的单位:px-> 像素
	//GetSystemMetrics(SM_CXSCREEN)获取当前屏幕的宽
	//GetSystemMetrics(SM_CYSCREEN)获取当前屏幕的高
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));


	//设置窗口风格  去除标题（WS_CAPTION标题）
	// GetWindowLong获取 窗口样式
	//GWL_STYLE：窗口的一种样式
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);

	//设置窗口位置
	//更新指定窗口的指定多窗口位置结构HWND_TOPMOST
	SetWindowPos(hwnd, HWND_TOPMOST, 250,0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);// SWP_SHOWWINDOW显示窗口

	//设置为透明 
	// GWL_EXSTYLE一种风格
	LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	//设置窗口风格
	SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);
	//背景修改为黑色
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
	//点位  爱形状心周边的点  围成一个爱心的
	Point arr[46] = {
		{ 395, 268 },//第一个点位置
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
	//加载初始化图片
	InitImg();

	//歌词
	wchar_t buff[46][50] = {
		L"我听见雨滴落在",
		L"青青草地",
		L"我听见远方",
		L"下课钟声响起",
		L"可是我没有",
		L"听见你的声音",
		L"认真",
		L"呼唤我姓名",
		L"爱上你",
		L"的时候还不懂感情",
		L"离别了",
		L"才觉得",
		L"刻骨铭心",
		L"为什么",
		L"没有发现",
		L"遇见了你",
		L"是生命",
		L"最好的事情",
		L"也许当时",
		L"忙着微笑和哭泣",
		L"忙着追逐",
		L"天空中的流星",
		L"人理所当然",
		L"的忘记",
		L"是谁风里雨里",
		L"一直默默守护",
		L"在原地",
		L"原来你是我",
		L"最想留住的幸运",
		L"原来我们",
		L"和爱情曾经靠得那么近",
		L"那为我",
		L"对抗世界的决定",
		L"那陪我",
		L"淋的雨",
		L"一幕幕都是你",
		L"一尘不染的真心",
		L"与你相遇",
		L"好幸运",
		L"可我已失去",
		L"为你泪流满面",
		L"的权利",
		L"但愿在",
		L"我看",
		L"不到",
		L"的天际"
	};

	//通过时间做随机数的种子
	srand((unsigned)time(NULL));

	//1.打开我们的音频文件 open x.mp3
	mciSendString(_T("open 音乐//xxx.mp3"), 0, 0, 0);
	////2.播放音频文件  play x.mp3
	mciSendString(_T("play 音乐//xxx.mp3"), 0, 0, 0);

	//随机数  /**/
	//for循环遍历显示46个点打印图片
	for (int i = 0; i < 46; i++) {

		//设置文本颜色  settextcolor
		//颜色深浅范围0-255     rand%256 随机产生颜色范围为0-255
		settextcolor(/*RGB(rand() % 256, rand() % 256, rand() % 256)*/RGB(94, 10, 36));
		//打印图片绘制46张图片根据每一张图片的x，y值
		putimage(arr[i].x, arr[i].y, &img[i % 10]);

		//打印文字
		outtextxy(arr[i].x, arr[i].y, buff[i]);

		Sleep(80);
	}

	//MOUSEMSG m;

	int add = 0;

	while (1)//让图片不停随机更换，在打印出来
	{
		//清除设备描述表
		cleardevice();
		for (int i = 0; i < 46; i++) {
			//设置文本颜色  settextcolor
			//settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			putimage(arr[i].x, arr[i].y, &img[(i + add) % 10]);
			outtextxy(arr[i].x, arr[i].y, buff[(i+add)%46]);
		}
	//输出图片
		putimage(274, 311, &img_Big[add % 10]);
		add++;
		Sleep(1000);
	}

	system("pause");
	closegraph();
	return 0;
}