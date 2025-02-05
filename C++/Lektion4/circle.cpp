//
// Created by Chu Ha Thanh on 2024-11-28.
//

#include "circle.h"
const float PI = 3.14159;

Circle::Circle(float radius) {
	this->radius = radius;
}

Circle::Circle() {
	this->radius = 0.0f;
}

float Circle::getRadius() const {
	return this -> radius;
}

void Circle::setRadius(float radius) {
	this->radius = radius;
}

float Circle::calcCircumference() {
	float ference = PI * (this->radius) * 2;
	return ference;
}

float Circle::calculateArea() {
	float radien = this->radius / 2;
	float area = PI * radien * radien;
	return area;
}

bool Circle::operator==(const Circle &other) const {
	bool equal = false;
	if (this -> radius == other.radius) {
		equal = true;
	}
	return equal;
}

bool Circle::operator!=(const Circle &other) const {
	bool diffirent = false;
	if (this->radius != other.radius) {
		diffirent = true;
	}
	return diffirent;
}


