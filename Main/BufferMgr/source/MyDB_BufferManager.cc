
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

using namespace std;

MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr, long) {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPage () {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr, long) {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
	return nullptr;		
}

void MyDB_BufferManager :: unpin (MyDB_PageHandle unpinMe) {
}

MyDB_BufferManager :: MyDB_BufferManager (size_t pgSize, size_t pgNum, string tmpFile) {

	// initialization
	this->pageSize = pgSize;
	this->numPages = pgNum;
	this->tempFile = tmpFile;

	// allocate memory
	char * buffer;
	buffer = (char*) malloc (this->pageSize * this->numPages);
	if(buffer == NULL)  {
        std::cout<<"failed"<<endl;
        exit(1);
    }
	else std::cout<<"successful"<<endl;

    // open tmpFile
    int tmp = open(this->tempFile.c_str(), O_CREAT | O_RDWR | O_FSYNC, 0666);
    std::cout<< tmp<< endl;
    lseek(tmp, 64, SEEK_SET);
    int wt;
    wt = write(tmp, "123", 20);
    std::cout<<wt<<endl;


}

MyDB_BufferManager :: ~MyDB_BufferManager () {
}
	
#endif


