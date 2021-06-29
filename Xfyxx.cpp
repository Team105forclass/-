// Xfyxx.cpp : implementation file
//

#include "stdafx.h"
#include "jszfglxt.h"
#include "Xfyxx.h"
#include "Flist.h"

extern int Nf;
extern CFlist flat[20];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXfyxx dialog


CXfyxx::CXfyxx(CWnd* pParent /*=NULL*/)
	: CDialog(CXfyxx::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXfyxx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CXfyxx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXfyxx)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXfyxx, CDialog)
	//{{AFX_MSG_MAP(CXfyxx)
	ON_BN_CLICKED(IDC_BUTTON_ZJFY, OnButtonZjfy)
	ON_BN_CLICKED(IDC_BUTTON_SCFY, OnButtonScfy)
	ON_BN_CLICKED(IDC_BUTTON_XGXX, OnButtonXgxx)
	ON_BN_CLICKED(IDC_BUTTON_SQZF, OnButtonSqzf)
	ON_BN_CLICKED(IDC_BUTTON_SQMD, OnButtonSqmd)
	//}}AFX_MSG_MAP
	/*ON_BN_CLICKED(IDCANCEL, &CXfyxx::OnBnClickedCancel)*/
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXfyxx message handlers

BOOL CXfyxx::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"��������",LVCFMT_CENTER,120);
	m_list.InsertColumn(1,"���",LVCFMT_CENTER,120);
	m_list.InsertColumn(2,"��������",LVCFMT_CENTER,120);
	m_list.InsertColumn(3,"��������",LVCFMT_CENTER,120);

	//���
	int i;
	m_list.DeleteAllItems();
	for (i=0;i<Nf;i++) InsertN(i,i);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CXfyxx::InsertN(int n, int l)
{
	CString p;
	switch (flat[n].lev)
	{	
	case 0: m_list.InsertItem(l,"A");	break;
	case 1: m_list.InsertItem(l,"B");		break;
	case 2: m_list.InsertItem(l,"C");	break;
	case 3: m_list.InsertItem(l,"D");		break;
	case 4: m_list.InsertItem(l,"E");	break;
	case 5: m_list.InsertItem(l,"F");		break;
	case 6: m_list.InsertItem(l,"G");	break;
	}	
	p.Format(_T("%d"),flat[n].are);
	m_list.SetItemText(l,1,p);
	p.Format(_T("%d"),flat[n].sp);
	m_list.SetItemText(l,2,p);
	p.Format(_T("%d"),flat[n].n);
	m_list.SetItemText(l,3,p);	
}

void CXfyxx::DeleteN(int n)
{
	for(int i=n;i<(Nf-1);i++)
		flat[i]=flat[i+1];
	Nf--;
}

void CXfyxx::OnButtonZjfy() 
{

	if (IDOK==zjfy.DoModal())
	{
		InsertN(Nf-1,Nf-1);
	}
}

void CXfyxx::OnButtonScfy() 
{
	
	int row=m_list.GetSelectionMark();
	if (row==-1) 
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING);
		return;
	}
	if (AfxMessageBox("���Ҫɾ����?",MB_YESNO|MB_ICONWARNING)==IDYES)
	{
		m_list.DeleteItem(row);
		DeleteN(row);
	}
}

void CXfyxx::OnButtonXgxx() 
{
	//�޸���Ϣ
	int row=m_list.GetSelectionMark();
	if (row==-1) 
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING);
		return;
	}
	xgxx.p=row;
	if (IDOK==xgxx.DoModal())
	{
		m_list.DeleteItem(row);
		InsertN(row,row);
	}
}

void CXfyxx::OnButtonSqzf() 
{
	
	int row = m_list.GetSelectionMark();
	if (row==-1)
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING);
		return;
	}
	sqzf.p = row;
	sqzf.DoModal();
	if (success == true) {
		m_list.DeleteAllItems();
		for (int i = 0; i < Nf; i++) InsertN(i, i);
	}
	success = false;
}

void CXfyxx::OnButtonSqmd() 
{
	//��������
	int row = m_list.GetSelectionMark();
	if (row==-1)
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING); 
		return;
	}
	sqmd.p=row;
	sqmd.DoModal();
}


//void CXfyxx::OnBnClickedCancel()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CDialog::OnCancel();
//}
