
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>
#include <unordered_map>
#include <map>

using namespace std;

MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr ptr, long id) {

    MyDB_table_page tp1 = MyDB_table_page (ptr, id);
    unordered_map<MyDB_table_page, MyDB_Page, MyHash, MyEqualTo>::iterator it = this->tpmap.find(tp1);
    if(it == this->tpmap.end()){
        std::cout<<"not find"<<endl;
        // not found
        shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, ptr, id);
        return make_shared<MyDB_PageHandleBase>(pg);
    }
    else{
        // found, just return
        std::cout<<"find it"<<endl;
        shared_ptr<MyDB_Page> pg(&(it->second));
        return make_shared<MyDB_PageHandleBase>(pg);
    }
}

MyDB_PageHandle MyDB_BufferManager :: getPage () {
    MyDB_TablePtr tppointer = make_shared<MyDB_Table>(this->tempFile,this->tempFile);
    shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, tppointer, 0);
    return make_shared<MyDB_PageHandleBase>(pg);
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr ptr, long id) {
    MyDB_table_page tp1 = MyDB_table_page (ptr, id);
    unordered_map<MyDB_table_page, MyDB_Page, MyHash, MyEqualTo>::iterator it = this->tpmap.find(tp1);
    if(it == tpmap.end()){
        std::cout<<"not find"<<endl;
        shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, ptr, id);
        pg.get()->setpin(true);
        return make_shared<MyDB_PageHandleBase>(pg);
    }
    else{
        std::cout<<"find it"<<endl;
        shared_ptr<MyDB_Page> pg(&it->second);
        return make_shared<MyDB_PageHandleBase>(pg);
    } 

}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
    MyDB_TablePtr tppointer = make_shared<MyDB_Table>(this->tempFile,this->tempFile);
    shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, tppointer, 0);
    pg.get()->setpin(true);
    return make_shared<MyDB_PageHandleBase>(pg);
}

void MyDB_BufferManager :: unpin (MyDB_PageHandle unpinMe) {
    unpinMe.get()->unpin();
}

MyDB_BufferManager :: MyDB_BufferManager (size_t pgSize, size_t pgNum, string tmpFile) {

	// initialization
	this->pageSize = pgSize;
	this->numPages = pgNum;
	this->tempFile = tmpFile;

	// allocate memory
	this->buffer = (char*) malloc (this->pageSize * this->numPages);
	if(this->buffer == NULL)  {
        std::cout<<"failed"<<endl;
        exit(1);
    }
	else std::cout<<"successful"<<endl;

    // open tmpFile
    this->tmp = open(this->tempFile.c_str(), O_CREAT | O_RDWR | O_FSYNC, 0666);
    std::cout<< this->tmp<< endl;
    lseek(tmp, 64, SEEK_SET);
    ssize_t wt;
    wt = write(tmp, "123", 20);
    std::cout<<wt<<endl;

    MyDB_TablePtr table1 = make_shared <MyDB_Table> ("tempTable", "foobar");
    MyDB_table_page tp = MyDB_table_page(table1, 0);
//    MyDB_tpptr ptr1 = make_shared <MyDB_table_page> (table1, 0);
    std::pair<MyDB_table_page, MyDB_Page> pair1(tp, MyDB_Page());
    this->tpmap.insert(pair1);



}

MyDB_BufferManager :: ~MyDB_BufferManager () {
}


long MyDB_BufferManager::getts() {
    return this->timestamp;
}

void MyDB_BufferManager::setts(long nts) {
    this->timestamp = nts;
}

MyDB_table_page::MyDB_table_page(MyDB_TablePtr table, long id) {
    this->tbptr = table;
    this->pgid = id;
}

MyDB_table_page::~MyDB_table_page() {

}


const long MyDB_table_page::getpgid() const{
    return this->pgid;
}

const MyDB_TablePtr& MyDB_table_page::getTablePtr() const{
    return this->tbptr;
}

shared_ptr<MyDB_table_page> MyDB_BufferManager::checklru(long lru){
    map<long, MyDB_table_page>::iterator iterator1 = this->lrumap.find(lru);
    if(iterator1 == this->lrumap.end()){
        return nullptr;
    }
    else{
        return shared_ptr<MyDB_table_page>  (& (iterator1->second));
    }

}

void MyDB_BufferManager::updateLRU(shared_ptr<MyDB_Page> pgptr) {

    long lrunum = pgptr->getLRU();

    // new timestamp or lru number
    this->timestamp++;

    // update lrunum in object
    pgptr->setLRU(this->timestamp);

    MyDB_table_page nID = MyDB_table_page(pgptr.get()->getTable(), pgptr.get()->getPageID());
    std::pair<long, MyDB_table_page> npair1(this->timestamp, nID);
    this->lrumap.insert(npair1);

    unordered_map<MyDB_table_page, MyDB_Page, MyHash, MyEqualTo>::iterator iterator1 = this->tpmap.find(nID);

    if(iterator1 != this->tpmap.end()){
        // exist
        // can use a better way
        this->tpmap.erase(nID);

    }

    std::pair<MyDB_table_page, MyDB_Page> npair(nID, *pgptr.get());
    this->tpmap.insert(npair);

    shared_ptr<MyDB_table_page> check = this->checklru(pgptr->getLRU());

    // lru is full or object is contained in lrumap
    if(check != nullptr){
        // lru is full or map contain
        this->lrumap.erase(lrunum);
    }

}

#endif


