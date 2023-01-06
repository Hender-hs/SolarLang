#pragma once

#include <iostream>
#include <fstream>

namespace SolarLang::FileStream {

    template<typename TStream> class File
    {
    public:
        TStream          file;
        std::filebuf*   ptrBuffer;
        std::size_t     fileSize;
        char*           fileBuffer;

    protected:
        std::string     _path;

        void _openFile()
        {
            file.open(_path, TStream::binary);
        }

        void _closeFile()
        {
            file.close();
        }

    };

    

    class Reader : public File<std::ifstream>
    {
    public:
        Reader(std::string path);

        ~Reader();

        char* read();
        
        void displayFile() { _printFile(); };

    private:

        void _getFileSize();

        void _allocMemoryForFile();

        void _getFileData();

        void _printFile();
    };


    class Writter : public File<std::ofstream>
    {
    public:
        Writter(std::string path);

        void write(char buffer[], int length);

    private:
        void _writeOnFile(char buffer[], int length);
    };
}



#if 0
int main();

#endif
