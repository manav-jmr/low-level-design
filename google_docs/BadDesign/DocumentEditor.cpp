#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<fstream>

using namespace std;

class DocumentEditor {
    private:
        vector<string> elements;
        string ren;
    
    public:
        void addText(string text)
        {
            elements.push_back(text);
        }

        void addImage(string image)
        {
            elements.push_back(image);
        }

        string renderDocument() 
        {
            if(ren.empty())
            {
                string res;
                for(auto it : elements)
                {
                    if(it.size() > 4 && (it.substr(it.size()-4) == ".jpg" || it.substr(it.size()-4) == ".png"))
                    {
                        res += "[Image: " + it + "]" + "\n";
                    }
                    else 
                    {
                        res += it + "\n";
                    }
                }

                ren = res;
            }

            return ren;
        }

        void saveToFile() 
        {
            ofstream file("document.txt");
            if(file.is_open())
            {
                file << renderDocument();
                file.close();
                cout << "Document save to document.txt" << endl;
            }
            else 
            {
                cout << "Error : unable to open file for writing." << endl;
            }
        }
};

int main()
{
    DocumentEditor* editor = new DocumentEditor();
    editor->addText("Hello , world!");
    editor->addImage("picture.jpg");
    editor->addText("This is a document editor ");

    cout << editor->renderDocument() << endl;

    editor->saveToFile();
}