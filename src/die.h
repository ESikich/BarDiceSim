#ifndef DIE_H
#define DIE_H

class Die{
public:
	int value_;
	bool holding_;

	void Roll();

	Die();
	~Die();
};

#endif