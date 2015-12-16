// tblOrder_Side.h : CtblOrder_Side의 선언입니다.

#pragma once

// 코드 생성 위치 2015년 12월 16일 수요일, 오후 6:09

class CtblOrder_SideAccessor
{
public:
	LONG m_order_id;
	LONG m_side_id;
	LONG m_side_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dwside_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dwside_priceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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

	DEFINE_COMMAND_EX(CtblOrder_SideAccessor, L" \
	SELECT \
		order_id, \
		side_id \
		FROM dbo.tblOrder_Side")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_COLUMN_MAP(CtblOrder_SideAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_side_price, m_dwside_priceLength, m_dwside_priceStatus)
	END_COLUMN_MAP()
};
class CtblOrder_SideInsertAccessor
{
public:
	LONG m_order_id;
	LONG m_side_id;
	LONG m_side_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dwside_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dwside_priceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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

	DEFINE_COMMAND_EX(CtblOrder_SideInsertAccessor, L" \
	INSERT INTO dbo.tblOrder_Side VALUES (?, ?, ?) ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblOrder_SideInsertAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_side_price, m_dwside_priceLength, m_dwside_priceStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrder_SideInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
	//END_COLUMN_MAP()
};
class CtblOrder_SideSelectWhereIdAccessor
{
public:
	LONG m_order_id;
	LONG m_side_id;
	LONG m_side_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dwside_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dwside_priceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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

	DEFINE_COMMAND_EX(CtblOrder_SideSelectWhereIdAccessor, L" \
	SELECT * FROM dbo.tblOrder_Side WHERE order_id = ? ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblOrder_SideSelectWhereIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblOrder_SideSelectWhereIdAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_side_price, m_dwside_priceLength, m_dwside_priceStatus)
	END_COLUMN_MAP()
};
class CtblOrder_SideUpdateAccessor
{
public:
	LONG m_order_id;
	LONG m_side_id;
	LONG m_side_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dwside_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dwside_priceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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

	DEFINE_COMMAND_EX(CtblOrder_SideUpdateAccessor, L" \
	UPDATE dbo.tblOrder_Side SET side_id = ?, side_price = ? WHERE order_id = ? ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblOrder_SideUpdateAccessor)		
		COLUMN_ENTRY_LENGTH_STATUS(1, m_side_id, m_dwside_idLength, m_dwside_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_side_price, m_dwside_priceLength, m_dwside_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrder_SideInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
	//END_COLUMN_MAP()
};
class CtblOrder_SideDeleteAccessor
{
public:
	LONG m_order_id;
	LONG m_side_id;
	LONG m_side_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dworder_idStatus;
	DBSTATUS m_dwside_idStatus;
	DBSTATUS m_dwside_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dworder_idLength;
	DBLENGTH m_dwside_idLength;
	DBLENGTH m_dwside_priceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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

	DEFINE_COMMAND_EX(CtblOrder_SideDeleteAccessor, L" \
	DELETE FROM dbo.tblOrder_Side WHERE order_id = ? ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblOrder_SideDeleteAccessor)		
		COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblOrder_SideInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_order_id, m_dworder_idLength, m_dworder_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_side_id, m_dwside_idLength, m_dwside_idStatus)
	//END_COLUMN_MAP()
};
template <class T>
class CtblOrder_Side : public CCommand<CAccessor<T> >
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


