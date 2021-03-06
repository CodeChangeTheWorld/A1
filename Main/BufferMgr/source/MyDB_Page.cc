//
// Created by Liu Fang on 1/24/17.
//

#ifndef PAGE_C
#define PAGE_C

#include <iostream>
#include "MyDB_Page.h"
#include "MyDB_BufferManager.h"

MyDB_Page::MyDB_Page(MyDB_BufferManager* manager, MyDB_TablePtr ptr,long id){
    this->bfmanager= manager;
    this->tableptr = ptr;
    this->pageid = id;
    pin = false;
    dirty = false;
    lru_counter = 0;
    offset = 0;
}
long MyDB_Page::getLRU() {
    return this->lru_counter;
}
void MyDB_Page::setLRU(long lru) {
    this->lru_counter = lru;
}
long MyDB_Page::getOffset() {
    return this->offset;
}
void MyDB_Page::setOffset(long offset) {
    this->offset = offset;
}
bool MyDB_Page::getDirty() {
    return this->dirty;
}
void MyDB_Page::setDirty(bool dirty) {
    this->dirty = dirty;
}
MyDB_Page::~MyDB_Page() {
}

bool MyDB_Page::getpin() {
    return this->pin;
}

void MyDB_Page::setpin(bool pinvalue) {
    this->pin = pinvalue;
}

MyDB_TablePtr MyDB_Page::getTable(){
    return this->tableptr;
}

long MyDB_Page::getPageID(){
    return this->pageid;
}

MyDB_BufferManager* MyDB_Page::getBufferManager() {
    return this->bfmanager;
}


#endif
