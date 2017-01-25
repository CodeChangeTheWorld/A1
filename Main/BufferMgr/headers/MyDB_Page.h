//
// Created by Liu Fang on 1/24/17.
//

#ifndef A1_MYDB_PAGE_H
#define A1_MYDB_PAGE_H


class MyDB_Page{
    long lru_counter;
    bool dirty;
    bool pin;
    long offset;

public:

    MyDB_Page();
    long getLRU();
    void setLRU(long lru);
    long getOffset();
    void setOffset(long offset);
    bool getDirty();
    void setDirty(bool dirty);
    ~MyDB_Page();
};

#endif //A1_MYDB_PAGE_H