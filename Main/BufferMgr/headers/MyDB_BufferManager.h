
#ifndef BUFFER_MGR_H
#define BUFFER_MGR_H

#include <unordered_map>
#include <map>
#include <iostream>
#include "MyDB_PageHandle.h"
#include "MyDB_Table.h"
#include "MyDB_Page.h"

using namespace std;

class MyDB_table_page{
public:
    MyDB_table_page(MyDB_TablePtr table, long id);

    ~MyDB_table_page();

    const MyDB_TablePtr& getTablePtr() const;

    const long getpgid() const;

    MyDB_TablePtr gettableptr();
    long getpageid();

private:

    MyDB_TablePtr tbptr;
    long pgid;

};
//typedef shared_ptr <MyDB_table_page> MyDB_tpptr;


class MyHash
{
public:

    size_t operator()(const MyDB_table_page& ptr) const
    {
        hash<string> sh;
        return sh(ptr.getTablePtr()->getName() + "/"
                  + ptr.getTablePtr()->getStorageLoc() + "/"
                  + to_string(ptr.getpgid()));
    }
};

class MyEqualTo {
public:

    bool operator()(const MyDB_table_page& p1,const MyDB_table_page& p2)  const
    {
        return (p1.getTablePtr()->getName() + "/"
               + p1.getTablePtr()->getStorageLoc() + "/"
               + to_string(p1.getpgid())).compare(p2.getTablePtr()->getName() + "/"
                                                  + p2.getTablePtr()->getStorageLoc() + "/"
                                                  + to_string(p2.getpgid()))!=0;
    }
};


class MyDB_BufferManager {

public:

	// THESE METHODS MUST APPEAR AND THE PROTOTYPES CANNOT CHANGE!

	// gets the i^th page in the table whichTable... note that if the page
	// is currently being used (that is, the page is current buffered) a handle 
	// to that already-buffered page should be returned
	MyDB_PageHandle getPage (MyDB_TablePtr whichTable, long i);

	// gets a temporary page that will no longer exist (1) after the buffer manager
	// has been destroyed, or (2) there are no more references to it anywhere in the
	// program.  Typically such a temporary page will be used as buffer memory.
	// since it is just a temp page, it is not associated with any particular 
	// table
	MyDB_PageHandle getPage ();

	// gets the i^th page in the table whichTable... the only difference 
	// between this method and getPage (whicTable, i) is that the page will be 
	// pinned in RAM; it cannot be written out to the file
	MyDB_PageHandle getPinnedPage (MyDB_TablePtr whichTable, long i);

	// gets a temporary page, like getPage (), except that this one is pinned
	MyDB_PageHandle getPinnedPage ();

	// un-pins the specified page
	void unpin (MyDB_PageHandle unpinMe);

	// creates an LRU buffer manager... params are as follows:
	// 1) the size of each page is pageSize 
	// 2) the number of pages managed by the buffer manager is numPages;
	// 3) temporary pages are written to the file tempFile
	MyDB_BufferManager (size_t pageSize, size_t numPages, string tempFile);
	
	// when the buffer manager is destroyed, all of the dirty pages need to be
	// written back to disk, any necessary data needs to be written to the catalog,
	// and any temporary files need to be deleted
	~MyDB_BufferManager ();

	// FEEL FREE TO ADD ADDITIONAL PUBLIC METHODS

    long getts();
    void setts(long nts);

    void updateLRU(shared_ptr<MyDB_Page>  p);
    void writeBack(shared_ptr<MyDB_Page>  p);
    shared_ptr<MyDB_table_page> checklru(long lru);
	void* getBytes(shared_ptr<MyDB_Page>  p);
    map <long, MyDB_table_page> lrumap;
//    unordered_map<MyDB_table_page, MyDB_Page, MyHash, MyEqualTo> tpmap;
    map<shared_ptr<MyDB_table_page>, shared_ptr<MyDB_Page>, MyEqualTo> tpmap;
//    map<shared_ptr<MyDB_table_page>, shared_ptr<MyDB_Page>> tpmap;
private:

	// YOUR STUFF HERE
	int pageSize, numPages;
	string tempFile;
    char * buffer;
    int tmp;
    long timestamp;
};



#endif


