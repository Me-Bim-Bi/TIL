#ifndef NOTEPAD_H
#define NOTEPAD_H
#include "Article.h"

class Notepad:public Article {
private:
	int nrOfPage;
	string cover;
public:
	Notepad(string articleNr = "?", int nrOfPage = 0, string cover = "hard");
	virtual ~Notepad();

	string description() const override;
};




#endif
