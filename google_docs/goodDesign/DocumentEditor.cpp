#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

class DocumentElement {
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement {
    private:
        string text;
    public:
        TextElement(string text)
        {
            this->text = text;
        }
        string render()
        {
            return text; 
        }
};

class ImageElement : public DocumentElement {
    private:
        string imagePath;
    public:
        ImageElement(string path)
        {
            this->imagePath = path;
        }

        string render()
        {
            return "[Image : " + imagePath + "]";
        }
};

class NewLineElement : public DocumentElement {
    public:
        string render()
        {
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement {
    public:
        string render ()
        {
            return "\t";
        }
};

class Document {
    private:
        vector<DocumentElement*> documentElements;
    public:
        void addElement(DocumentElement* element)
        {
            documentElements.push_back(element);
        }

        vector<DocumentElement*> getElements()
        {
            return documentElements;
        }
};

class DocumentRenderer {
    private:
        Document* document;
    public:
        DocumentRenderer(Document* document)
        {
            this->document = document;
        }

        string render()
        {
            string renderedDocument;
            for(DocumentElement* element : document->getElements())
            {
                renderedDocument += element->render();
            }
            return renderedDocument;
        }
};

class Persistence {
    public:
        virtual void save(string data) = 0;
};

class saveToFile : public Persistence {
    public:
        void save(string data)
        {
            ofstream outFile("document.txt");
            if(outFile.is_open())
            {
                outFile << data;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            }
            else 
            {
                cout << "Error : Unable to open file for writing. " << endl;
            }
        }
};

class saveToDB : public Persistence {
    public:
        void save(string data)
        {
            cout << "Saved to db.... " << endl;
        }
};

class DocumentEditor {
    private:
        Document* document;
    public:
        DocumentEditor(Document* document)
        {
            this->document = document;
        }

        void addText(string text)
        {
            document->addElement(new TextElement(text));
        }

        void addImage(string imagePath)
        {
            document->addElement(new ImageElement(imagePath));
        }

        void addNewLine()
        {
            document->addElement(new NewLineElement());
        }

        void addTabSpace()
        {
            document->addElement(new TabSpaceElement());
        }
};

class Client {
    private:
        Document* document;
        DocumentEditor* editor;
        Persistence* storage;
        DocumentRenderer* renderer;
    public:
        Client(Document* document , DocumentEditor* editor , Persistence* storage , DocumentRenderer* renderer)
        {
            this->document = document;
            this->editor = editor;
            this->storage = storage;
            this->renderer = renderer;

        }

        void prepareDocument()
        {
            editor->addText("Hello, World!");
            editor->addNewLine();
            editor->addText("This is a real world document editor example. ");
            editor->addNewLine();
            editor->addTabSpace();
            editor->addText("Indented text after a tab space. ");
            editor->addNewLine();
            editor->addImage("picture.jpg");
        }

        string renderDocument()
        {
            return renderer->render();
        }

        void printDocument()
        {
            cout << renderDocument() << endl;
        }

        void saveDocument()
        {
            storage->save(renderDocument());
        }

        void execute()
        {
            prepareDocument();
            printDocument();
            saveDocument();
        }
};

int main()
{
    Document* document = new Document();
    DocumentEditor* editor = new DocumentEditor(document);
    Persistence* storage = new saveToFile();
    DocumentRenderer* renderer = new DocumentRenderer(document);
    Client* client = new Client(document, editor, storage, renderer);

    client->execute();

    return 0;
}
