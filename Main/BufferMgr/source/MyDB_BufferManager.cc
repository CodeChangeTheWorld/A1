
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include<fcntl.h>
#include <unistd.h>

using namespace std;

MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr ptr, long id) {

    MyDB_table_page tp1 = MyDB_table_page (ptr, id);
    map<MyDB_table_page, shared_ptr<MyDB_Page>,MyEqualTo>::iterator it = this->tpmap.find(tp1);
    if(it == this->tpmap.end()){
        // not found
        shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, ptr, id);
        return make_shared<MyDB_PageHandleBase>(pg);
    }
    else{
        // found, just return
        shared_ptr<MyDB_Page> lrupage = it->second;
        return make_shared<MyDB_PageHandleBase>(lrupage);
    }
}

MyDB_PageHandle MyDB_BufferManager :: getPage () {
    MyDB_TablePtr tppointer = make_shared<MyDB_Table>(this->tempFile,this->tempFile);
    shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, tppointer, 0);
    return make_shared<MyDB_PageHandleBase>(pg);
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr ptr, long id) {
    MyDB_table_page tp1 = MyDB_table_page (ptr, id);
    map<MyDB_table_page, shared_ptr<MyDB_Page>,MyEqualTo>::iterator it = this->tpmap.find(tp1);
    if(it == tpmap.end()){
        shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, ptr, id);
        pg.get()->setpin(true);
        return make_shared<MyDB_PageHandleBase>(pg);
    }
    else{
        shared_ptr<MyDB_Page> lrupage = it->second;
        return make_shared<MyDB_PageHandleBase>(lrupage);
    }

}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
    MyDB_TablePtr tppointer = make_shared<MyDB_Table>(this->tempFile,this->tempFile);
    shared_ptr<MyDB_Page> pg = make_shared<MyDB_Page>(this, tppointer, this->tmp++);
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
    this->timestamp = 0;
    //this->lrumap = new map<long, MyDB_table_page>();

	// allocate memory
	this->buffer = (char*) malloc (this->pageSize * this->numPages);
	if(this->buffer == NULL)  {
        exit(1);
    }




}

MyDB_BufferManager :: ~MyDB_BufferManager () {

    for(map<long, MyDB_table_page>::iterator i = this->lrumap.begin(); i != this->lrumap.end(); i++){
        shared_ptr<MyDB_Page> ptr = tpmap.find(i->second)->second;
        if(ptr != nullptr && ptr->getDirty()){
            this->writeBack(ptr);
        }
    }
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

long MyDB_table_page::getpageid() {
    return this->pgid;
}

MyDB_TablePtr MyDB_table_page::gettableptr() {
    return this->tbptr;
}

shared_ptr<MyDB_table_page> MyDB_BufferManager::checklru(long lru){
    map<long, MyDB_table_page>::iterator iterator1 = this->lrumap.find(lru);

    if(iterator1 == this->lrumap.end()){
        return nullptr;
    }
    else{
        shared_ptr<MyDB_table_page> ptr = make_shared<MyDB_table_page>(iterator1->second.gettableptr(), iterator1->second.getpageid());
        return ptr;
    }

}



void* MyDB_BufferManager::getBytes(shared_ptr<MyDB_Page>  page){
        shared_ptr<MyDB_table_page> curpage = this->checklru(page.get()->getLRU());
        if(curpage == nullptr){
            //full
            if(numPages <= this->lrumap.size()){
                shared_ptr<MyDB_Page> lrupage;

                for(map<long, MyDB_table_page>::iterator i = this->lrumap.begin(); i != this->lrumap.end(); i++){
                    if(!this->tpmap.find(i->second)->second.get()->getpin()){
                        lrupage = tpmap.find(i->second)->second;
                        break;
                    }
                }

                if(lrupage->getDirty()){
                    writeBack(lrupage);
                    lrupage->setDirty(false);
                }
                long curoffset = lrupage->getOffset();
                long oldlrunum = lrupage->getLRU();
                page->setLRU(oldlrunum);
                page->setOffset(curoffset);
            }
            else{
                page->setOffset(this->pageSize * (this->lrumap.size()));
            }

            MyDB_TablePtr table = page->getTable();
            // open tmpFile
            int file = open(table->getStorageLoc().c_str(), O_CREAT | O_RDWR | O_FSYNC, 0666);
            lseek(file, pageSize*(page->getPageID()), SEEK_SET);
            int bytes_read = read(file,(this->buffer)+page->getOffset(),pageSize);
        }
        this->updateLRU(page);
        return (this->buffer)+page->getOffset();
}

void MyDB_BufferManager::updateLRU(shared_ptr<MyDB_Page>  pgptr) {
    long lrunum = pgptr->getLRU();

    // new timestamp or lru number
    this->timestamp++;

    // update lrunum in object
    pgptr.get()->setLRU(this->timestamp);

    MyDB_table_page nID(pgptr.get()->getTable(), pgptr.get()->getPageID());
    std::pair<long, MyDB_table_page> npair1(this->timestamp, nID);
    this->lrumap.insert(npair1);
    map<MyDB_table_page, shared_ptr<MyDB_Page>, MyEqualTo>::iterator iterator1;
    iterator1 = this->tpmap.find(nID);

    if(iterator1 != this->tpmap.end()){
        // exist
        // can use a better way
        iterator1->second = pgptr;
    }
    else{
        std::pair<MyDB_table_page, shared_ptr<MyDB_Page>> npair(nID, pgptr);
        this->tpmap.insert(npair);
    }



    shared_ptr<MyDB_table_page> check = this->checklru(lrunum);

    // lru is full or object is contained in lrumap
    if(check != nullptr){
        // lru is full or map contain
        this->lrumap.erase(lrunum);
    }

}

void MyDB_BufferManager::wroteBytes(shared_ptr<MyDB_Page> page) {
    shared_ptr<MyDB_table_page> curpage = this->checklru(page.get()->getLRU());
    if(curpage == nullptr){
        //full
        if(numPages <= this->lrumap.size()){
            shared_ptr<MyDB_Page> lrupage;

            for(map<long, MyDB_table_page>::iterator i = this->lrumap.begin(); i != this->lrumap.end(); i++){
                if(!this->tpmap.find(i->second)->second.get()->getpin()){
                    lrupage = tpmap.find(i->second)->second;
                    break;
                }
            }

            if(lrupage->getDirty()){
                writeBack(lrupage);
                lrupage->setDirty(false);
            }
            long curoffset = lrupage->getOffset();
            long oldlrunum = lrupage->getLRU();
            page->setLRU(oldlrunum);
            page->setOffset(curoffset);
        }

    }
    page->setDirty(true);
    this->updateLRU(page);

}

void MyDB_BufferManager::writeBack(shared_ptr<MyDB_Page>  p) {
    MyDB_TablePtr table = p->getTable();
    int file = open(table->getStorageLoc().c_str(), O_CREAT | O_RDWR | O_FSYNC, 0666);
    lseek(file, pageSize*(p->getPageID()), SEEK_SET);
    int write_read = write(file,(this->buffer)+p->getOffset(),pageSize);
    close(file);
}
#endif


