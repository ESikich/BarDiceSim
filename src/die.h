#ifndef DIE_H
#define DIE_H

class Die{
	int value_;
	bool is_held_;
	
public:
	bool IsHeld() const;
	int Value() const;
	
	void Roll();
	void Hold();
	
	void Init();
	void Reset();
	
	Die();
	~Die();
};

#endif