#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>


using namespace std;
namespace fs = filesystem;

vector<string> split_into_paragraphs(string text) {
    vector<string> paragraphs;
    stringstream iss(text);
    string paragraph;
    while (getline(iss, paragraph)) {
        if (!paragraph.empty()) {
            paragraphs.push_back("<p>" + paragraph + "</p>");
        }
    }
    return paragraphs;
}

string convert_to_html(string text) {
    vector<string> paragraphs = split_into_paragraphs(text);
    stringstream ss;
    ss << "<!DOCTYPE html>\n"
       << "<html>\n"
       << "<head>\n"
       << "<meta charset=\"UTF-8\">\n"
       << "</head>\n"
       << "<body>\n";
    for (const auto &paragraph: paragraphs) {
        ss << paragraph << "\n";
    }
    ss << "</body>\n"
       << "</html>";
    return ss.str();
}

int main() {
    fs::path currentDir = "C:\\Users\\artm\\CLionProjects\\laba12\\testFiles";
    for (const auto &entry: fs::directory_iterator(currentDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            string text;
            ifstream infile(entry.path());
            if (infile.is_open()) {
                getline(infile, text, '\0');
                infile.close();
            } else {
                cerr << "Error: could not open file " << entry.path() << endl;
                continue;
            }
            string html = convert_to_html(text);
            fs::path html_path = const_cast<fs::path &>(entry.path()).replace_extension(".html");
            ofstream outfile(html_path);
            if (outfile.is_open()) {
                outfile << html;
                outfile.close();
            } else {
                cerr << "Error: could not create file " << html_path << endl;
                continue;
            }
            cout << "Converted " << entry.path() << " to " << html_path << endl;
        }
    }
    return 0;
}
