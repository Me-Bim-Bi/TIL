//
// Created by Chu Ha Thanh on 2024-11-28.
//

#ifndef CIRCLE_H
#define CIRCLE_H



class Circle {
private:
	float radius;
public:
	Circle(float radius);
	Circle();
	float getRadius() const;
	void setRadius(float radius);
	float calcCircumference();
	float calculateArea();
	bool operator == (const Circle& other) const;
	bool operator != (const Circle& other) const;
};



#endif //CIRCLE_H
