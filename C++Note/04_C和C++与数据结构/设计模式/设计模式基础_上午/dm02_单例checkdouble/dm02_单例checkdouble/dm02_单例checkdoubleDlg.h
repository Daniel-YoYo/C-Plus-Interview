
// dm02_����checkdoubleDlg.h : ͷ�ļ�
//

#pragma once


// Cdm02_����checkdoubleDlg �Ի���
class Cdm02_����checkdoubleDlg : public CDialogEx
{
// ����
public:
	Cdm02_����checkdoubleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DM02_CHECKDOUBLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
