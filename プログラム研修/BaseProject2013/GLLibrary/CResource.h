#pragma once
#pragma once
/**
* @file		AsSet.h
* @brief	リソース管理クラス
*
* @author	shinya nagakawa
*/


#include <map>
#include <vector>

class CResource {
	char m_name[128];
public:
	CResource(){ memset(m_name, 0, sizeof(m_name)); }
	/**
	* @fn
	* コンストラク
	* @brief コンストラクタ
	* @param name [in]　名前
	*/
	CResource(char *name) { memcpy(m_name, name, sizeof(m_name)); }
	/**
	* @fn
	* デストラクタ
	* @brief デストラクタ
	*/
	virtual ~CResource() {};
	/**
	* @fn
	* 名前の取得
	* @brief 名前の取得
	* @return 名前
	*/
	std::string GetName() const {
		return m_name;
	}
	/**
	* @fn
	* リソースサイズ取得
	* @brief リソースサイズ取得
	*/
	virtual unsigned int GetDataSize() { return 0; };

	/**
	* @fn
	* リソース開放処理
	* @brief リソース開放処理
	*/
	virtual void Release() {};
	friend class CResourceManager;

};
class CResourceManager {
private:
	std::map<int,std::map<std::string, CResource*>> m_list;
	static CResourceManager*	m_instance;
public:
	static CResourceManager* GetInstance() {
		if (!m_instance) m_instance = new CResourceManager;
		return m_instance;
	}
	/**
	* @fn　リソースを全て破棄する
	* @brief リソースを全て破棄する
	*/
	static void ClearInstance() {
		if (!m_instance) return;
		delete m_instance;
		m_instance = nullptr;
	}
	CResourceManager();
	~CResourceManager();
	/**
	* @fn
	* リソースの追加
	* @brief リソースの追加
	*/
	void Add(CResource* res,int group=0);
	void Add(std::string name, CResource* res,int group=0);
	/**
	* @fn
	* リソースの取得
	* @brief リソースのの取得
	* @param name [in]　リソースの名前
	* @return リソース
	*/
	CResource* Get(std::string name, int group = 0);
	/**
	* @fn
	* リソースの削除
	* @brief リソースのの削除
	* @param name [in]　リソースの名前
	*/
	void Delete(std::string name, int group = 0);
	/**
	* @fn
	* リソースの削除
	* @brief リソースのの削除
	* @param name [in]　リソースグループ
	*/
	void Delete(int group = 0);

	unsigned int GetDataSize();
};
#define ADD_RESOURCE(name,obj) if(!CResourceManager::GetInstance()->Get(name)) CResourceManager::GetInstance()->Add(name,obj)
#define GET_RESOURCE(name,T) dynamic_cast<T>(CResourceManager::GetInstance()->Get(name))
#define COPY_RESOURCE(name,T) *dynamic_cast<T>(CResourceManager::GetInstance()->Get(name))
