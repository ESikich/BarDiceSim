#ifndef DIE_H
#define DIE_H

class Die{
	int value_;
	bool holding_;
	
public:
	void Roll();
	void Reset();
	bool Held();
	void Hold();
	int Value();
	
	Die();
	~Die();
};

#endif