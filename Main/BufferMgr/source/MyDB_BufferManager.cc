
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
        //
    }
    else{
        // found, just return
        std::cout<<"find it"<<endl;
        shared_ptr<MyDB_Page> pg(&it->second);
//        pg.reset(&it->second);
        return make_shared<MyDB_PageHandleBase>(pg);
    }
    return nullptr;
}

MyDB_PageHandle MyDB_BufferManager :: getPage () {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr ptr, long id) {
    MyDB_table_page tp1 = MyDB_table_page (ptr, id);
    unordered_map<MyDB_table_page, MyDB_Page, MyHash, MyEqualTo>::iterator it = this->tpmap.find(tp1);
    if(it == tpmap.end()){
        std::cout<<"not find"<<endl;
        return nullptr;
    }
    else{
        std::cout<<"find it"<<endl;
        shared_ptr<MyDB_Page> pg(&it->second);
//        pg.reset(&it->second);
        return make_shared<MyDB_PageHandleBase>(pg);
    }

}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
	return nullptr;		
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
	if(buffer == NULL)  {
        std::cout<<"failed"<<endl;
        exit(1);
    }
	else std::cout<<"successful"<<endl;

    // open tmpFile
    this->tmp = open(this->tempFile.c_str(), O_CREAT | O_RDWR | O_FSYNC, 0666);
    std::cout<< tmp<< endl;
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

#endif


