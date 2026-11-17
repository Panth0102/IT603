
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string content;
int pos = 0;

// Skip spaces and newline characters
void skipSpaces() {
    while (pos < content.length() &&
           isspace(content[pos])) {
        pos++;
    }
}

// Read a JSON string
string readString() {
    string result;

    pos++; // Skip opening quotation mark

    while (pos < content.length() && content[pos] != '"') {
        if (content[pos] == '\\' && pos + 1 < content.length()) {
            pos++;
            switch (content[pos]) {
                case 'n': result += '\n'; break;
                case 't': result += '\t'; break;
                case 'r': result += '\r'; break;
                default: result += content[pos];
            }
        }
        else {
            result += content[pos];
        }
        pos++;
    }

    if (pos >= content.length())
        throw runtime_error("Unterminated string");

    pos++; // Skip closing quotation mark
    return result;
}

// Read a JSON value
string readValue() {
    skipSpaces();

    if (pos >= content.length())
        throw runtime_error("Missing value");

    // Read string
    if (content[pos] == '"') {
        return "\"" + readString() + "\"";
    }

    // Read number, boolean or null
    int start = pos;

    while (pos < content.length() &&
           content[pos] != ',' &&
           content[pos] != '}' &&
           content[pos] != ']' &&
           !isspace(content[pos])) {
        pos++;
    }

    if (start == pos)
        throw runtime_error("Invalid value");

    string value = content.substr(start, pos - start);

    if (value != "true" && value != "false" && value != "null") {
        try {
            size_t used;
            stod(value, &used);

            if (used != value.length())
                throw runtime_error("Invalid value");
        }
        catch (...) {
            throw runtime_error("Invalid value");
        }
    }

    return value;
}

// Forward declaration
void displayJSON(int indent);

// Read and display JSON objects
void readObject(int indent) {
    pos++; // Skip {

    skipSpaces();

    if (pos < content.length() && content[pos] == '}') {
        pos++;
        cout << string(indent, ' ') << "{}" << endl;
        return;
    }

    while (pos < content.length()) {
        skipSpaces();

        if (pos >= content.length() || content[pos] != '"')
            throw runtime_error("Expected object key");

        string key = readString();

        skipSpaces();

        if (pos >= content.length() || content[pos] != ':')
            throw runtime_error("Expected ':'");

        pos++;

        skipSpaces();

        cout << string(indent, ' ') << key << " : ";

        if (pos < content.length() &&
            (content[pos] == '{' || content[pos] == '[')) {
            cout << endl;
            displayJSON(indent + 4);
        }
        else {
            cout << readValue() << endl;
        }

        skipSpaces();

        if (pos < content.length() && content[pos] == ',') {
            pos++;
        }
        else if (pos < content.length() && content[pos] == '}') {
            pos++;
            return;
        }
        else {
            throw runtime_error("Expected ',' or '}'");
        }
    }

    throw runtime_error("Unclosed object");
}

// Read and display JSON arrays
void readArray(int indent) {
    pos++; // Skip [

    skipSpaces();

    if (pos < content.length() && content[pos] == ']') {
        pos++;
        cout << string(indent, ' ') << "[]" << endl;
        return;
    }

    int index = 0;

    while (pos < content.length()) {
        skipSpaces();

        cout << string(indent, ' ') << "[" << index++ << "] ";

        if (pos < content.length() &&
            (content[pos] == '{' || content[pos] == '[')) {
            cout << endl;
            displayJSON(indent + 4);
        }
        else {
            cout << readValue() << endl;
        }

        skipSpaces();

        if (pos < content.length() && content[pos] == ',') {
            pos++;
        }
        else if (pos < content.length() && content[pos] == ']') {
            pos++;
            return;
        }
        else {
            throw runtime_error("Expected ',' or ']'");
        }
    }

    throw runtime_error("Unclosed array");
}

// Display JSON based on its type
void displayJSON(int indent) {
    skipSpaces();

    if (pos >= content.length())
        throw runtime_error("Unexpected end of JSON");

    if (content[pos] == '{') {
        readObject(indent);
    }
    else if (content[pos] == '[') {
        readArray(indent);
    }
    else {
        cout << string(indent, ' ') << readValue() << endl;
    }
}

int main() {
    string filename;

    // Take file name from user
    cout << "Enter JSON file name/path: ";
    getline(cin, filename);

    // Open JSON file
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    // Read complete file content
    string line;

    while (getline(file, line)) {
        content += line + "\n";
    }

    file.close();

    try {
        // Display parsed JSON data
        cout << "\nJSON File Contents:\n";
        cout << "--------------------------\n";

        displayJSON(0);

        skipSpaces();

        if (pos != content.length())
            throw runtime_error("Unexpected characters after JSON data");

    }
    catch (const exception& e) {
        cout << "\nError: Invalid JSON file!" << endl;
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
