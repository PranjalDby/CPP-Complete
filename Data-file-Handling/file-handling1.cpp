#include <iostream>
#include<fstream>
using namespace std;

#define max 1024
int main(){

    // file-handling:
    // Two ways to open a file: 1st way
    ofstream writeFile;
    // writeFile.open("info.txt");
    // reading the data from file-to-the console.
    ifstream reading;
    fstream dualmode("info.txt", ios::app);
    int opt;
    cout << "1 for output stream 2 for input stream 3 for append: " << endl;
    cin >> opt;
    int size = 0;
    cin.ignore();
    switch (opt)
    {
        case 1:
            writeFile.open("info.txt");
            cout << "Enter some text: " << endl;
            char buffer[max];
            buffer[max - 1] = '\0';
            cin.getline(buffer, 1024);
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                size++;
            }
            writeFile.write(buffer, size);
            writeFile.close();
            break;
        
        case 2:
            reading.open("info.txt");
            char readed[max];
            readed[max - 1] = '\0';
            reading.read(readed, max);
            cout << readed << endl;
            reading.close();
            break;

        case 3:
            cout << "Opening a file using constructor\n";
            if (dualmode.good())
            {
                cout << "Stream is healthy.\n";
                char content[1024];
                content[max - 1] = '\0';
                cout << "Enter some content: " << endl;
                cin.ignore();
                cin.getline(content, max);
                for (int i = 0; content[i] != '\0'; i++)
                {
                    size++;
                }
                dualmode.write(content,size);
                size = 0;
                dualmode.close();
            }
            break;
        default:
            break;
    }
    
    return 0;
}