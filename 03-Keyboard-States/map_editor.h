#ifndef __QTREE_H__
#define __QTREE_H__

#include "define.h"

class QuadTree
{
public:
	QuadTree(RECT bound, int level = 1);
	~QuadTree();
	void Clear();
	void InsertStaticObject(CGameObject* gameObject);
	static void InsertDynamicObject(CGameObject* gameObject);
	void Retrieve(std::vector<CGameObject*>& gameObjectsOut, CGameObject* gameObject);

protected:
	static int MAX_OBJECT_IN_REGION;
	static int MAX_LEVEL;

	RECT		mBound;
	int			mLevel;
	QuadTree** mNodes;
	std::vector<CGameObject*>		mListStaticGameObject;
	static std::vector<CGameObject*> mListDynamicGameObject;

	bool IsContain(CGameObject* gameObject);
	void Split();
};



#endif // !__QTREE_H__