// Jsmd.cpp : implementation file
//

#include "stdafx.h"
#include "jszfglxt.h"
#include "Jsmd.h"
#include "Nlist.h"

extern CNlist user[20];
extern int Nt;

bool s=0;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJsmd dialog


CJsmd::CJsmd(CWnd* pParent /*=NULL*/)
	: CDialog(CJsmd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJsmd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJsmd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJsmd)
	DDX_Control(pDX, IDC_BUTTON_SX, m_sx);
	DDX_Control(pDX, IDC_BUTTON_ZJJL, m_zjjl);
	DDX_Control(pDX, IDC_BUTTON_XGJL, m_xgjl);
	DDX_Control(pDX, IDC_BUTTON_SCJL, m_scjl);
	DDX_Control(pDX, IDC_BUTTON_JTCYXX, m_jtcyxx);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJsmd, CDialog)
	//{{AFX_MSG_MAP(CJsmd)
	ON_BN_CLICKED(IDC_BUTTON_ZJJL, OnButtonZjjl)
	ON_BN_CLICKED(IDC_BUTTON_SCJL, OnButtonScjl)
	ON_BN_CLICKED(IDC_BUTTON_XGJL, OnButtonXgjl)
	ON_BN_CLICKED(IDC_BUTTON_JTCYXX, OnButtonJtcyxx)
	ON_BN_CLICKED(IDC_BUTTON_SX, OnButtonSx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CJsmd::OnLvnItemchangedList1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJsmd message handlers

BOOL CJsmd::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"����",LVCFMT_CENTER,60);
	m_list.InsertColumn(1,"�Ա�",LVCFMT_CENTER,60);
	m_list.InsertColumn(2,"��������",LVCFMT_CENTER,120);
	m_list.InsertColumn(3,"��������",LVCFMT_CENTER,110);
	m_list.InsertColumn(4,"ͣ������",LVCFMT_CENTER,110);
	m_list.InsertColumn(5,"��Ӫ����",LVCFMT_CENTER,120);
	m_list.InsertColumn(6,"��������",LVCFMT_CENTER,120);
	m_list.InsertColumn(7,"�ŵ�����",LVCFMT_CENTER,120);
	m_list.InsertColumn(8,"Ԥ����",LVCFMT_CENTER,120);
	
	
	for (int i=0;i<Nt;i++) InsertN(i,i);

	m_scjl.EnableWindow(FALSE);
	m_xgjl.EnableWindow(FALSE);
	m_jtcyxx.EnableWindow(FALSE);
	if (Nt==0) m_sx.EnableWindow(FALSE);

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CJsmd::InsertN(int n,int l)
{
	CString p,q,o;
	
	//����
	m_list.InsertItem(l,user[n].name);

	//�Ա�
	switch (user[n].sex)
	{	
		case 0: m_list.SetItemText(l,1,"��");break;
		case 1: m_list.SetItemText(l,1,"Ů");break;
	}

	//��������
	switch (user[n].tit)
	{	
		case 0: m_list.SetItemText(l,2,"��������");		break;
		case 1: m_list.SetItemText(l,2,"ҵ����ѯ");	break;
		case 2: m_list.SetItemText(l,2,"ҵ������");		break;
		case 3: m_list.SetItemText(l,2,"����");		break;
	}
	//qizuriqi
	p.Format(_T("%d"),user[n].by);
	q.Format(_T("%d"),user[n].bm);
	o=p+'.'+q;
	m_list.SetItemText(l,3,o);

	//ͣ������
	p.Format(_T("%d"),user[n].wy);
	q.Format(_T("%d"),user[n].wm);
	o=p+'.'+q;
	m_list.SetItemText(l,4,o);

	//��Ӫ����
	switch (user[n].men)
	{	
		case 0: m_list.SetItemText(l,5,"����ʳƷ");break;
		case 1: m_list.SetItemText(l,5,"���η�װ");break;
		case 2: m_list.SetItemText(l,5,"��ױ�ջ�");break;
		case 3: m_list.SetItemText(l,5,"������Ŀ");break;
	}

	
	o.Format(_T("%d"),user[n].num);
	m_list.SetItemText(l,6,o);

	//��������
	switch (user[n].lev)
	{	
		case 0: m_list.SetItemText(l,7,"A");	break;
		case 1: m_list.SetItemText(l,7,"B");		break;
		case 2: m_list.SetItemText(l,7,"C");	break;
		case 3: m_list.SetItemText(l,7,"D");		break;
		case 4: m_list.SetItemText(l,7,"E");	break;
		case 5: m_list.SetItemText(l,7,"F");		break;
		case 6: m_list.SetItemText(l,7,"G");	break;
	}

	//���
	o.Format(_T("%d"),user[n].money);
	m_list.SetItemText(l,8,o);

}

void CJsmd::DeleteN(int n)
{	
	for(int i=n;i<(Nt-1);i++)
		user[i]=user[i+1];
	Nt--;
}

void CJsmd::OnButtonZjjl() 
{
	//���Ӽ�¼
	if (zjjl.DoModal()==IDOK)
	{
		InsertN(Nt-1,Nt-1);
		//for (int i=0;i<user[Nt].num;)
			/*if(jtcy.DoModal()==IDOK)
			{
				user[Nt].mem[i].name=jtcy.m_n;
				user[Nt].mem[i].sex=jtcy.m_s;
				user[Nt].mem[i].by=jtcy.m_y;
				user[Nt].mem[i].bm=jtcy.m_m;
				i++;
			}*/
		m_sx.EnableWindow(TRUE);
	};
}

void CJsmd::OnButtonScjl() 
{
	//ɾ����¼
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
	if (Nt==0)
	{
		m_sx.EnableWindow(FALSE);
		m_scjl.EnableWindow(FALSE);
		m_xgjl.EnableWindow(FALSE);
		m_jtcyxx.EnableWindow(FALSE);
	}
}

void CJsmd::OnButtonXgjl() 
{
	//�޸ļ�¼
	int row=m_list.GetSelectionMark();
	if (row==-1) 
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING);
		return;
	}
	xgjl.setP(row);
	xgjl.DoModal();
	m_list.DeleteItem(row);
	InsertN(row,row);
}

void CJsmd::OnButtonJtcyxx() 
{
	//�⻧��Ϣ
	int row=m_list.GetSelectionMark();
	if (row==-1) 
	{
		AfxMessageBox("û��ѡ���¼!",MB_OK|MB_ICONWARNING);
		return;
	}
	jtcyxx.p=row;
	jtcyxx.DoModal();
}

void CJsmd::OnButtonSx() 
{
	//ɸѡ
	int l=0;
	if (IDOK==sx.DoModal())
	{
		m_list.DeleteAllItems();
		for (int i=0;i<Nt;i++)
			if (user[i].visable)
			{
				InsertN(i,l);
				l++;
			}
		if (l<Nt)
		{
			s=1;
			m_zjjl.EnableWindow(FALSE);
			m_scjl.EnableWindow(FALSE);
			m_xgjl.EnableWindow(FALSE);
			m_jtcyxx.EnableWindow(FALSE);
		}
		else
		{
			s=0;
			m_zjjl.EnableWindow(TRUE);
			m_scjl.EnableWindow(TRUE);
			m_xgjl.EnableWindow(TRUE);
			m_jtcyxx.EnableWindow(TRUE);
		}

	}
}

void CJsmd::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//����
	int row=m_list.GetSelectionMark();
	if ((row==-1)||s)
	{
		m_scjl.EnableWindow(FALSE);
		m_xgjl.EnableWindow(FALSE);
		m_jtcyxx.EnableWindow(FALSE);
	}
	else
	{
		m_zjjl.EnableWindow(TRUE);
		m_scjl.EnableWindow(TRUE);
		m_xgjl.EnableWindow(TRUE);
		m_jtcyxx.EnableWindow(TRUE);
	}
	*pResult = 0;
}

void CJsmd::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//�޸ļ�¼
	int row=m_list.GetSelectionMark();
	if (row==-1) return;
	xgjl.setP(row);
	xgjl.DoModal();
	m_list.DeleteItem(row);
	InsertN(row,row);
	*pResult = 0;
}


void CJsmd::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
