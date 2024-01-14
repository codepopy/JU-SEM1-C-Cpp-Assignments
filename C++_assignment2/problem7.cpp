#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class FileStatistics {
private:
    int charCount;
    int wordCount;
    int lineCount;

public:
    FileStatistics() : charCount(0), wordCount(0), lineCount(0) {}

    void analyzeFile( const char* filename) {
        ifstream inputFile;
        inputFile.open(filename);

        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open the file " << filename << endl;
            return;
        }else{
        	cout<<"file opened.."<<endl;
		}

        string line;
        while (getline(inputFile, line)) {
            charCount += line.length();
            wordCount += countWords(line);
            lineCount++;
        }

        inputFile.close();
    }

    int countWords(const string& line) {
        stringstream ss(line);
        string word;
        int count = 0;

        while (ss >> word) {
            count++;
        }

        return count;
    }

    void displayStatistics() {
        cout << "Number of characters: " << charCount << endl;
        cout << "Number of words: " << wordCount << endl;
        cout << "Number of lines: " << lineCount << endl;
    }
};

int main() {
    string filename;

    cout << "Enter the filename: ";
    cin>>filename;
    
    

    FileStatistics fileStats;
    fileStats.analyzeFile(filename.c_str());
    fileStats.displayStatistics();

    return 0;
}

