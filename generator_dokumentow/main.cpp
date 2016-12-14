#include <iostream>

//scenariusz: artykul / blog
// artykul w ascii, blog w html
//builder: html / tekstowy

using namespace std;


class Document
{
public:
    void setParagraf(string *par) {
        paragraf = par;
    }
    void set_linia_pozioma(string l) {
        linia_pozioma = l;
    }
    void set_poczatek(string p) {
        poczatek = p;
    }
    void set_koniec(string k) {
        koniec = k;
    }
private:
    string *paragraf;
    string linia_pozioma;
    string poczatek;
    string koniec;
};

//glowny interface
class Builder
{
 public:
    void new_Document() {
        document = new Document();
    }
    Document* get_Document() {
        return document;
    }
    virtual void build_paragraf(string par)=0;
    virtual void build_linia_pozioma()=0;
    virtual void build_poczatek()=0;
    virtual void build_koniec()=0;
 protected:
     Document *document;
};

class HTML : public Builder
{
public:
    HTML() : Builder() {}
    void build_paragraf(string par) {
        document->setParagraf("<p>" + par + "</p>");
    }
    void build_linia_pozioma() {
        document->set_linia_pozioma("<hr>");
    }
    void build_poczatek() {
        document->set_poczatek("<html>");
    }
    void build_koniec() {
        document->set_koniec("</html>");
    }
};

class ASCII : public Builder
{
public:
    ASCII() : Builder() {}

    void build_paragraf(string *par) {
        for(int i = 0; i>par->size(); ++i) {

        }
        document->setParagraf(par);
    }
    void build_linia_pozioma() {
        document->set_linia_pozioma("-----------------------------");
    }
    void build_poczatek() {
        document->set_poczatek("");
    }
    void build_koniec() {
        document->set_koniec("");
    }
};

class Director
{
public:
    void set_Builder(Builder *b) {
        builder = b;
    }
    Document* get_Document() {
        return builder->get_Document();
    }
    void set_Document() {
        builder->build_poczatek();
        builder->build_paragraf("");
        builder->build_linia_pozioma();
        builder->build_koniec();
    }
private:
    Builder *builder;
};


int main()
{

    return 0;
}
