#include <iostream>
#include <fstream>
#include "FileStream.hpp"

namespace FileStream {
    
    template<typename stream> class File
    {
    public:
        stream          file;
        std::filebuf*   ptrBuffer;
        std::size_t     fileSize;
        char*           fileBuffer;

    protected:
        std::string     _path;

        virtual void _openFile()
        {
            file.open(_path, stream::binary);
        }

        virtual void _closeFile()
        {
            file.close();
        }
    };

    class Reader : public File<std::ifstream>
    {
    public:
        Reader(std::string path)
        {
            _path = path;
        }

        char* read()
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

    private:

        void _getFileSize()
        {
            ptrBuffer = file.rdbuf();
            fileSize = ptrBuffer->pubseekoff(0, file.end, file.in);
            ptrBuffer->pubseekpos(0, file.in);
        }

        void _allocMemoryForFile()
        {
            fileBuffer = new char[fileSize];
        }

        void _getFileData()
        {
            ptrBuffer->sgetn(fileBuffer, fileSize);
        }

        void _printFile() 
        {
            std::cout.write(fileBuffer, fileSize);
        }
    };


    class Writter : public File<std::ofstream>
    {
    public:
        Writter(std::string path)
        {
            _path = path;
        }

        void write(char buffer[], int length)
        {
            _openFile();
            _writeOnFile(buffer, length);
            _closeFile();
        };

    private:
        void _writeOnFile(char buffer[], int length)
        {
            file.write(buffer, length);
        }
    };
}


#if 0

int main()
{   

#ifdef MACRO
    char buff[] = "Write This Simple Phraser \n a1111111 \n \t 2222222222222";
    FileStream::Writter* wr = new FileStream::Writter("./filetest.txt");
    wr->write(buff, sizeof(buff));
#endif

    FileStream::Reader* rd = new FileStream::Reader("./filetest.txt");
    char* flData = rd->read();
    std::cout << flData << std::endl;
    return 0;
}


#endif
