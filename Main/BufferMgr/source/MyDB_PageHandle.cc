
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include <iostream>
#include "MyDB_PageHandle.h"
#include "MyDB_BufferManager.h"

void *MyDB_PageHandleBase :: getBytes () {
    return this->pgobject.get()->getBufferManager()->getBytes(pgobject);
}

void MyDB_PageHandleBase :: wroteBytes () {
    this->pgobject.get()->getBufferManager()->wroteBytes(pgobject);
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
    this->unpin();
}

void MyDB_PageHandleBase::unpin() {
	this->pgobject.get()->setpin(false);
}

MyDB_PageHandleBase::MyDB_PageHandleBase(shared_ptr<MyDB_Page> page){
	this->pgobject = page;
}
#endif

