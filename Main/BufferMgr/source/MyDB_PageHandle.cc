
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include "MyDB_PageHandle.h"
#include "MyDB_BufferManager.h"

void *MyDB_PageHandleBase :: getBytes () {
//	long lru = this->pgobject.get()->getLRU();
    return this->pgobject.get()->getBufferManager()->getBytes(this->pgobject);
}

void MyDB_PageHandleBase :: wroteBytes () {
//    long lru = this->pgobject.get()->getLRU();
    this->pgobject.get()->getBufferManager()->updateLRU(this->pgobject);
    this->pgobject.get()->setDirty(true);
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
}

void MyDB_PageHandleBase::unpin() {
	this->pgobject.get()->setpin(false);
}

MyDB_PageHandleBase::MyDB_PageHandleBase(shared_ptr<MyDB_Page> page){
	this->pgobject = page;
}
#endif

