// tblCustomer.h : CtblCustomer�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2015�� 12�� 12�� �����, ���� 2:07

class CtblCustomerAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerAccessor, L" \
	SELECT \
		cus_id, \
		cus_name, \
		cus_phone, \
		cus_point \
		FROM dbo.tblCustomer")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CtblCustomerAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_cus_point, m_dwcus_pointLength, m_dwcus_pointStatus)
	END_COLUMN_MAP()
};
class CtblCustomerSelectAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerSelectAccessor, L" \
	SELECT \
		cus_id, \
		cus_name, \
		cus_phone, \
		cus_point \
		FROM dbo.tblCustomer")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CtblCustomerAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_cus_point, m_dwcus_pointLength, m_dwcus_pointStatus)
	END_COLUMN_MAP()
};
class CtblCustomerInsertAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerInsertAccessor, L" INSERT INTO dbo.tblCustomer (cus_name, cus_phone) VALUES(?, ?)")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.
	BEGIN_PARAM_MAP(CtblCustomerInsertAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
	END_PARAM_MAP()

};
class CtblCustomerUpdateAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerUpdateAccessor, L"UPDATE dbo.tblCustomer SET cus_name = ?, cus_phone = ? WHERE cus_id = ?")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.
	BEGIN_PARAM_MAP(CtblCustomerUpdateAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_PARAM_MAP()
};
class CtblCustomerDeleteAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerDeleteAccessor, L"DELETE FROM dbo.tblCustomer WHERE cus_id = ?")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.
	BEGIN_PARAM_MAP(CtblCustomerDeleteAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
	END_PARAM_MAP()
};
class CtblCustomerSelectWhereNameAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerSelectWhereNameAccessor, L" SELECT \
		cus_id, \
		cus_name, \
		cus_phone, \
		cus_point \
		FROM dbo.tblCustomer WHERE cus_name = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblCustomerSelectWhereNameAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblCustomerSelectWhereNameAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_cus_point, m_dwcus_pointLength, m_dwcus_pointStatus)
	END_COLUMN_MAP()
};
class CtblCustomerSelectWherePhoneAccessor
{
public:
	LONG m_cus_id;
	TCHAR m_cus_name[21];
	TCHAR m_cus_phone[14];
	LONG m_cus_point;

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwcus_idStatus;
	DBSTATUS m_dwcus_nameStatus;
	DBSTATUS m_dwcus_phoneStatus;
	DBSTATUS m_dwcus_pointStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwcus_idLength;
	DBLENGTH m_dwcus_nameLength;
	DBLENGTH m_dwcus_phoneLength;
	DBLENGTH m_dwcus_pointLength;


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

	DEFINE_COMMAND_EX(CtblCustomerSelectWherePhoneAccessor, L" SELECT \
		cus_id, \
		cus_name, \
		cus_phone, \
		cus_point \
		FROM dbo.tblCustomer WHERE cus_phone = ? ")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_PARAM_MAP(CtblCustomerSelectWherePhoneAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblCustomerSelectWherePhoneAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cus_id, m_dwcus_idLength, m_dwcus_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cus_name, m_dwcus_nameLength, m_dwcus_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cus_phone, m_dwcus_phoneLength, m_dwcus_phoneStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_cus_point, m_dwcus_pointLength, m_dwcus_pointStatus)
	END_COLUMN_MAP()
};
template <class T>
class CtblCustomer : public CCommand<CAccessor<T> >
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


