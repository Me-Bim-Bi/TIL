#include "Article.h"

Article::Article(string articleNr) {
	this->articleNr = articleNr;
}

Article::~Article() {
}

string Article::getArticleNr() const {
	return this->articleNr;
}

void Article::setArticleNr(const string &articleNr) {
	this->articleNr = articleNr;
}

string Article::description() const {
	return "Article number: " + articleNr;
}
