// tblBeverage.h : CtblBeverage의 선언입니다.

#pragma once

// 코드 생성 위치 2015년 12월 14일 월요일, 오전 3:20

class CtblBeverageAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageAccessor, L" \
	SELECT \
		bev_id, \
		bev_name, \
		bev_price \
		FROM dbo.tblBeverage")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_COLUMN_MAP(CtblBeverageAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_COLUMN_MAP()
};
class CtblBeverageSelectAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageSelectAccessor, L" \
	SELECT \
		bev_id, \
		bev_name, \
		bev_price \
		FROM dbo.tblBeverage")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_COLUMN_MAP(CtblBeverageSelectAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_COLUMN_MAP()
};
class CtblBeverageInsertAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageInsertAccessor, L" INSERT INTO dbo.tblBeverage (bev_name, bev_price) VALUES (?, ?)")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblBeverageInsertAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblBeverageInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	//END_COLUMN_MAP()
};
class CtblBeverageUpdateAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageUpdateAccessor, L" UPDATE dbo.tblBeverage SET bev_name = ?, bev_price = ? WHERE bev_id = ? ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblBeverageUpdateAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblBeverageInsertAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	//END_COLUMN_MAP()
};
class CtblBeverageDeleteAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageDeleteAccessor, L" DELETE FROM dbo.tblBeverage WHERE bev_id = ? ")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblBeverageDeleteAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
	END_PARAM_MAP()

	//BEGIN_COLUMN_MAP(CtblBeverageDeleteAccessor)
	//	COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
	//	COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	//END_COLUMN_MAP()
};
class CtblBeverageSelectWhereNameAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageSelectWhereNameAccessor, L" \
	SELECT \
		bev_id, \
		bev_name, \
		bev_price \
		FROM dbo.tblBeverage WHERE bev_name = ?")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblBeverageSelectWhereNameAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblBeverageSelectWhereNameAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_COLUMN_MAP()
};
class CtblBeverageSelectWherePriceAccessor
{
public:
	LONG m_bev_id;
	TCHAR m_bev_name[21];
	LONG m_bev_price;

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwbev_idStatus;
	DBSTATUS m_dwbev_nameStatus;
	DBSTATUS m_dwbev_priceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwbev_idLength;
	DBLENGTH m_dwbev_nameLength;
	DBLENGTH m_dwbev_priceLength;


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

	DEFINE_COMMAND_EX(CtblBeverageSelectWherePriceAccessor, L" \
	SELECT \
		bev_id, \
		bev_name, \
		bev_price \
		FROM dbo.tblBeverage WHERE bev_price = ?")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_PARAM_MAP(CtblBeverageSelectWherePriceAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_PARAM_MAP()

	BEGIN_COLUMN_MAP(CtblBeverageSelectWherePriceAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_bev_id, m_dwbev_idLength, m_dwbev_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_bev_name, m_dwbev_nameLength, m_dwbev_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_bev_price, m_dwbev_priceLength, m_dwbev_priceStatus)
	END_COLUMN_MAP()
};
template <class T>
class CtblBeverage : public CCommand<CAccessor<T> >
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


