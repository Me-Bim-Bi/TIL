#include "Notepad.h"
#include "Article.h"

Notepad::Notepad(string articleNr, int nrOfPage, string cover)
:Article(articleNr), nrOfPage(nrOfPage), cover(cover) {
}

Notepad::~Notepad() {
}

string Notepad::description() const {
	return "Notepad: " + Article::description() + " has " + to_string(nrOfPage)
	+ " pages and has " + cover + " cover.";
}
