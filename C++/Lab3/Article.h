#ifndef ARTICLE_H
#define ARTICLE_H
#include<string>


using namespace std;

class Article {
private:
	string articleNr;
public:
	Article(string articleNr = "?");
	virtual ~Article();

	string getArticleNr() const;
	void setArticleNr(const string& articleNr);
	virtual string description() const;
};

#endif
