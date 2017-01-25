//
// Created by Liu Fang on 1/24/17.
//

#ifndef A1_MYDB_PAGE_H
#define A1_MYDB_PAGE_H
#endif //A1_MYDB_PAGE_H

class MyDB_Page{
    long lru_counter;
    bool dirty;
    char* bytes;

public:
    MyDB_Page();
    char* getbytes();
    void setbytes(char* bytes);
    ~MyDB_Page();
};