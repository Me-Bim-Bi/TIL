//
// Created by Chu Ha Thanh on 2024-11-24.
//

#include "toycar.h"

ToyCar::ToyCar(string model, string color) {
	this->model = model;
	this->color = color;
}

ToyCar::ToyCar() {
	this->model ="? model";
	this->color="? color";
}

string ToyCar::getModel() const {
	return this->model;
}

string ToyCar::getColor() const {
	return this->color;
}

void ToyCar::setColor(const string &color) {
	this->color = color;
}

string ToyCar::toString() const {
	string result = model + " with the color " + color;
	return result;
}
