#include <iostream>
#include <string>
using namespace std;

string Printifier(const std::string& input, int i) {
    if (i) {
        string output;
        for (char c : input) {
            if (c == '\n') { output += "\\n"; }
            else if (c == '\"') { output += "\\\""; }
            else if (c == '\\') { output += "\\\\"; }
            else { output += c; }
        } return (i == 2) ? output : ("\nfor (int i = 0; i < 2; i++)\n cout << Printifier(\"" + output + "\",i);\n cout << \"\\n}\";");
    }
    else { return input; }
}

string code = "#include <iostream>\n#include <string>\nusing namespace std;\n                \nstring Printifier(const std::string& input, int i) {\n              if (i){\n              string output;\n              for (char c : input) {\n                      if (c == '\\n') { output += \"\\\\n\";}\n                      else if (c == '\\\"') { output += \"\\\\\\\"\";}\n   else if (c == '\\\\') { output += \"\\\\\\\\\"; }\n                   else { output += c; }\n              } return (i == 2) ? output : (\"\\nfor (int i = 0; i < 2; i++)\\n cout << Printifier(\\\"\" + output + \"\\\",i);\\n cout << \\\"\\\\n}\\\";\");\n                  }else { return input; } }\n";

int main() {
    cout << code << "\nstring code = \"" << Printifier(code, 2) << "\"; \n\n int main(){ \n";
    for (int i = 0; i < 2; i++)
        cout << Printifier("cout << code << \"\\nstring code = \\\"\" << Printifier(code, 2) << \"\\\";  \\n\\n int main(){\\n \";", i);

    cout << "\n}";
}
