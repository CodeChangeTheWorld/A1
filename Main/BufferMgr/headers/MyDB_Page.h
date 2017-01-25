//
// Created by Liu Fang on 1/24/17.
//

#ifndef A1_MYDB_PAGE_H
#define A1_MYDB_PAGE_H


#include "MyDB_Table.h"
//#include "MyDB_BufferManager.h"

class MyDB_BufferManager;

class MyDB_Page{
    long lru_counter;
    bool dirty;
    bool pin;
    long offset;
    MyDB_BufferManager* bfmanager;
    MyDB_TablePtr ptr;
    long pageid;

public:

    MyDB_Page();
    MyDB_Page(MyDB_BufferManager* bfmanager, MyDB_TablePtr ptr, long id);
    long getLRU();
    void setLRU(long lru);
    long getOffset();
    void setOffset(long offset);
    bool getDirty();
    void setDirty(bool dirty);
    void setpin(bool pinvalue);
    bool getpin();
    ~MyDB_Page();
};

#endif //A1_MYDB_PAGE_H