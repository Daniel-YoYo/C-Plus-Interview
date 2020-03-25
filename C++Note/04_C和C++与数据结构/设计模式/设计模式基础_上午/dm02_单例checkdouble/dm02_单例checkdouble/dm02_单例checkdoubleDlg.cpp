
// dm02_单例checkdoubleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "dm02_单例checkdouble.h"
#include "dm02_单例checkdoubleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdm02_单例checkdoubleDlg 对话框




Cdm02_单例checkdoubleDlg::Cdm02_单例checkdoubleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdm02_单例checkdoubleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdm02_单例checkdoubleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cdm02_单例checkdoubleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cdm02_单例checkdoubleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cdm02_单例checkdoubleDlg 消息处理程序

BOOL Cdm02_单例checkdoubleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cdm02_单例checkdoubleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cdm02_单例checkdoubleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cdm02_单例checkdoubleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static CCriticalSection cs;

class Singelton
{
private: //1构造函数私有化
	//C++的构造函数 不能保证是线程安全
	Singelton()
	{
		m_num ++;
		TRACE("Singelton begin\n");
		Sleep(1000);
		TRACE("Singelton end\n");
	}
public:
	static void printS()
	{
		TRACE("m_num:%d \n", m_num);
	}
public:  //2 提供全局访问点  
	
	static Singelton *GetSingelton()
	{
		//每一次GetSingelton时候，都需要判断single是否存在
		if (single == NULL)  
		{
			cs.Lock();
			if (single == NULL)
			{
				single = new Singelton; //线程1 线程2 线程3 都去调用了new Singelton 
			}
			cs.Unlock();
		}
		return single; //
	}
	
	/*
	static Singelton *GetSingelton()
	{
		return single; //
	}
	*/
		
private:
	static Singelton *single;
	static int m_num;
};
Singelton* Singelton::single = NULL;
int Singelton::m_num = 0;


void threadFunc(void *p)
{
	DWORD id = GetCurrentThreadId();
	Singelton::GetSingelton()->printS();
	TRACE("id:%d\n", id);
	return;
}
void main_1()
{
	int i = 0;
	int threadnum = 3;
	HANDLE  hThread[100];
	//_CRTIMP uintptr_t __cdecl _beginthread (_In_ void (__cdecl * _StartAddress) (void *),
	//	_In_ unsigned _StackSize, _In_opt_ void * _ArgList);

	for (i=0; i<threadnum; i++)
	{
		hThread[i] = (HANDLE)_beginthread(threadFunc, 0, NULL);
	}

	for (i=0; i<threadnum; i++)  //让主进程等待 所有子线程运行完毕
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
	TRACE("main \n");
}

void Cdm02_单例checkdoubleDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	main_1();

	//AfxMessageBox("ddd");
}
