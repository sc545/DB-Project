// tblOrder.h : CtblOrder�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2015�� 12�� 16�� ������, ���� 7:19

class CtblOrderAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderAccessor, L" \
	SELECT \
		order_id, \
		order_date, \
		order_used_point, \
		order_price, \
		order_save_point, \
		cus_id \
		FROM dbo.tblOrder")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CtblOrderAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class CtblOrderSelectAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderSelectAccessor, L" \
	SELECT \
		order_id, \
		order_date, \
		order_used_point, \
		order_price, \
		order_save_point, \
		cus_id \
		FROM dbo.tblOrder")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CtblOrderSelectAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class CtblOrderInsertAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderInsertAccessor, L" INSERT INTO dbo.tblOrder VALUES (?, ?, ?, ?, ?, ?) ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderInsertAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrderInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	//END_COLUMN_MAP()
};
class CtblOrderSelectWhereIdAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderSelectWhereIdAccessor, L" SELECT * FROM dbo.tblOrder WHERE order_id = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderSelectWhereIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)

	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblOrderSelectWhereIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class CtblOrderSelectWhereDateAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderSelectWhereDateAccessor, L" SELECT SUM(order_price) as order_price, COUNT(order_id) as order_id FROM dbo.tblOrder WHERE order_date = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderSelectWhereDateAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)

	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblOrderSelectWhereDateAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class CtblOrderSelectWhereCusIdAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderSelectWhereCusIdAccessor, L" SELECT * FROM dbo.tblOrder WHERE cus_id = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderSelectWhereCusIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)

	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblOrderSelectWhereCusIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_COLUMN_MAP()
};
class CtblOrderUpdateAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderUpdateAccessor, L" UPDATE dbo.tblOrder SET order_date = ?, order_used_point = ?, order_price = ?, order_save_point = ?, cus_id = ? WHERE order_id = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderUpdateAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrderUpdateAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	//END_COLUMN_MAP()
};
class CtblOrderDeleteAccessor
{
public:
	LONG m_order_id;
	TCHAR m_order_date[11];
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
	DBSTATUS m_dworder_dateStatus;
	DBSTATUS m_dworder_used_pointStatus;
	DBSTATUS m_dworder_priceStatus;
	DBSTATUS m_dworder_save_pointStatus;
	DBSTATUS m_dwcus_idStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dworder_dateLength;
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

	DEFINE_COMMAND_EX(CtblOrderDeleteAccessor, L" DELETE FROM dbo.tblOrder WHERE order_id = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblOrderDeleteAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrderUpdateAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_order_date, m_dworder_dateLength, m_dworder_dateStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_order_used_point, m_dworder_used_pointLength, m_dworder_used_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(4, m_order_price, m_dworder_priceLength, m_dworder_priceStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(5, m_order_save_point, m_dworder_save_pointLength, m_dworder_save_pointStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(6, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	//END_COLUMN_MAP()
};
template <class T>
class CtblOrder : public CCommand<CAccessor<T> >
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


