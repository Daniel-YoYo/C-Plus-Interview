
// dm02_����checkdoubleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dm02_����checkdouble.h"
#include "dm02_����checkdoubleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cdm02_����checkdoubleDlg �Ի���




Cdm02_����checkdoubleDlg::Cdm02_����checkdoubleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdm02_����checkdoubleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdm02_����checkdoubleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cdm02_����checkdoubleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cdm02_����checkdoubleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cdm02_����checkdoubleDlg ��Ϣ�������

BOOL Cdm02_����checkdoubleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cdm02_����checkdoubleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cdm02_����checkdoubleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cdm02_����checkdoubleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static CCriticalSection cs;

class Singelton
{
private: //1���캯��˽�л�
	//C++�Ĺ��캯�� ���ܱ�֤���̰߳�ȫ
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
public:  //2 �ṩȫ�ַ��ʵ�  
	
	static Singelton *GetSingelton()
	{
		//ÿһ��GetSingeltonʱ�򣬶���Ҫ�ж�single�Ƿ����
		if (single == NULL)  
		{
			cs.Lock();
			if (single == NULL)
			{
				single = new Singelton; //�߳�1 �߳�2 �߳�3 ��ȥ������new Singelton 
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

	for (i=0; i<threadnum; i++)  //�������̵ȴ� �������߳��������
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
	TRACE("main \n");
}

void Cdm02_����checkdoubleDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	main_1();

	//AfxMessageBox("ddd");
}
