#include "Enemy.h"




void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3;//min=3 and max=10
	this-> type = 0;
	this->speed = static_cast<float>(this->pointCount/5);
	this-> hpMax = static_cast<int>(this->pointCount);
	this-> hp = this->hpMax;
	this-> damage = this->pointCount;
	this-> points = this->pointCount;


}


void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount*2);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();

	this->initShape();//call init shape afterwards cause we will use point count after wards in this function
	this->shape.setPosition(pos_x, pos_y);
	
}

Enemy::~Enemy()
{
}

//Accessors

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

//functions

void Enemy::update()
{
	this->shape.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
