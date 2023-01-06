#include <iostream>
#include <fstream>
#include "FileStream.hpp"

using namespace SolarLang;

FileStream::Reader::Reader(std::string path)
{
    this->_path = path;
};


FileStream::Reader::~Reader()
{
    delete[] this->fileBuffer;
};


char* FileStream::Reader::read()
{
    _openFile();

    if (!file.is_open()) {
        std::cout << "File Not Found" << std::endl;
        return {};
    }

    _getFileSize();
    _allocMemoryForFile();
    _getFileData();
    _closeFile();
    
    return fileBuffer;
}


void FileStream::Reader::_getFileSize()
{
    // TODO: Analize this code carefuly
    ptrBuffer = file.rdbuf();
    fileSize = ptrBuffer->pubseekoff(0, file.end, file.in);
    ptrBuffer->pubseekpos(0, file.in);
}


void FileStream::Reader::_allocMemoryForFile()
{
    fileBuffer = new char[fileSize];
}


void FileStream::Reader::_getFileData()
{
    ptrBuffer->sgetn(fileBuffer, fileSize);
}


void FileStream::Reader::_printFile() 
{
    std::cout.write(fileBuffer, fileSize);
}


FileStream::Writter::Writter(std::string path)
{
    _path = path;
}


void FileStream::Writter::write(char buffer[], int length)
{
    _openFile();
    _writeOnFile(buffer, length);
    _closeFile();
};


void FileStream::Writter::_writeOnFile(char buffer[], int length)
{
    file.write(buffer, length);
}
