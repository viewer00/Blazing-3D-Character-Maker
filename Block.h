#pragma once

class Block
{
protected:
	__int16 slices;
	int type;
	int projectType;
	void update_type();
public:
	Block(int type = 0, int projectType = 8);
	Block(__int16 slices);
	bool equal(Block blk);
	int get_type();
	int get_projectType();
	__int16 get_slice();
	__int16 operator +(Block blk);
	__int16 operator -(Block blk);
	bool isOverlap(__int16 slices);
	static __int16 mk_slice(int type);
	static bool isOverlap(Block blk1, Block blk2);
	static Block combine(Block blk1, Block blk2);
};