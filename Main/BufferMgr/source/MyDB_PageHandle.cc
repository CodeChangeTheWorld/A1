
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
    this->pgobject.get()->setDirty(true);
//    long lru = this->pgobject.get()->getLRU();
    this->pgobject.get()->getBufferManager()->updateLRU(pgobject);
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
    std::cout<<"deconstructing"<<std::endl;
}

void MyDB_PageHandleBase::unpin() {
    cout<<"unping"<<endl;
	this->pgobject.get()->setpin(false);
}

MyDB_PageHandleBase::MyDB_PageHandleBase(shared_ptr<MyDB_Page> page){
	this->pgobject = page;
}
#endif

