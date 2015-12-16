// view_order.h : Cview_order�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2015�� 12�� 16�� ������, ���� 8:46

class Cview_orderAccessor
{
public:
	LONG m_order_id;
	LONG m_bev_id;
	LONG m_bev_size;
	LONG m_bev_hot_ice;
	LONG m_side_id;
	LONG m_order_used_point;
	LONG m_order_price;
	LONG m_order_save_point;
	LONG m_cus_id;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_sizeStatus;
	DBSTATUS m_dwbev_hot_iceStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_sizeLength;
	DBLENGTH m_dwbev_hot_iceLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dworder_used_pointLength;
	DBLENGTH m_dworder_priceLength;
	DBLENGTH m_dworder_save_pointLength;
	DBLENGTH m_dwcus_idLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
		hr = _db.OpenFromInitializationString(L"Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=HugCoffe;Data Source=K-PC\\SQLEXPRESS;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=K-PC;Use Encryption for Data=False;Tag with column collation when possible=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(Cview_orderAccessor, L" \
	SELECT \
		order_id, \
		bev_id, \
		bev_size, \
		bev_hot_ice, \
		side_id, \
		order_used_point, \
		order_price, \
		order_save_point, \
		cus_id \
		FROM dbo.view_order")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(Cview_orderAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_size, m_dwbev_sizeLength, m_dwbev_sizeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_bev_hot_ice, m_dwbev_hot_iceLength, m_dwbev_hot_iceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class Cview_orderSelectAccessor
{
public:
	LONG m_order_id;
	LONG m_bev_id;
	LONG m_bev_size;
	LONG m_bev_hot_ice;
	LONG m_side_id;
	LONG m_order_used_point;
	LONG m_order_price;
	LONG m_order_save_point;
	LONG m_cus_id;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_sizeStatus;
	DBSTATUS m_dwbev_hot_iceStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_sizeLength;
	DBLENGTH m_dwbev_hot_iceLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dworder_used_pointLength;
	DBLENGTH m_dworder_priceLength;
	DBLENGTH m_dworder_save_pointLength;
	DBLENGTH m_dwcus_idLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
		hr = _db.OpenFromInitializationString(L"Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=HugCoffe;Data Source=K-PC\\SQLEXPRESS;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=K-PC;Use Encryption for Data=False;Tag with column collation when possible=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(Cview_orderSelectAccessor, L" \
	SELECT \
		order_id, \
		bev_id, \
		bev_size, \
		bev_hot_ice, \
		side_id, \
		order_used_point, \
		order_price, \
		order_save_point, \
		cus_id \
		FROM dbo.view_order")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(Cview_orderSelectAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_size, m_dwbev_sizeLength, m_dwbev_sizeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_bev_hot_ice, m_dwbev_hot_iceLength, m_dwbev_hot_iceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
template <class T>
class Cview_order : public CCommand<CAccessor<T> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};


