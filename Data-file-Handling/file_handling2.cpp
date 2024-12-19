#include<iostream>
#include<fstream>

using namespace std;


int main(){

    //using file pointers:to sequencially or randomally access the data from file.

    fstream stream("info.txt");
    // since we are opening the file in reading mode so the file pointer accessor are seekg() and tellg();

    if(stream.is_open()){
        string mylines;
        if (stream.good())
        {
            // cout << stream.tellg(); // by-default it is pointing to the beg of file.

            //to-change the pointer
            stream.seekp(ios::beg);
            cout << "Pos of pointer during read = " << stream.tellp() << endl;
            cout << "After adding ❤️ to the end of file.\n";
            cout << "Write pointer pos = " << stream.tellg() << endl;
            const char *data = "Lovely,";
            int size = 0;
            for (int i = 0; data[i] != '\0'; i++)
            {
                size++;
            }
            stream.write(data,size);
            stream.seekg(0);
            // char buffer[1024];
            // stream.read(buffer, 1024);
            // cout << buffer << endl;
            while(!stream.eof()){
                std::getline(stream, mylines);
                cout << mylines << "";
            }
        }
    }
    stream.close();
}