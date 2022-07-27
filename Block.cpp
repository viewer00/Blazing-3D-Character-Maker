#include"block.h"
#include<Windows.h>
#define BLOCK_TYPE 8

// 记录着8种块的形状
__int16 sliceMap[8] = {
	0b0000000000000000,
	0b1111111111111111,
	0b1111111100000000,
	0b0000000011111111,
	0b0000011001101111,
	0b0011000011110011,
	0b1100111100001100,
	0b1111100110010000

};

//int type_cat[8][8] =
//{
//	{0, 1, 2, 3, 4, 5, 6, 7},
//	{1, 1, 1, 1, 1, 1, 1, 1},
//	{2, 1, 2, 1, -1, -1, -1, -1},
//	{3, 1, 1, 3, -1, -1, -1, -1},
//	{4 ,1, -1, -1, 4, -1, 1, -1},
//	{5, 1, -1, -1, -1, 5, -1, 1},
//	{6, 1, -1, -1, 1, -1, 6, -1},
//	{7, 1, -1, -1, -1, 1, -1, 7}
//};
void Block::update_type()
{
	// 常常是拼接完成后重新计算图形编号
	type = -1;
	for (int i = 0; i < BLOCK_TYPE; ++i)
		if (slices == sliceMap[i])
			type = i;
}

Block::Block(int type, int projectType)
{
	slices = sliceMap[type];
	this->type = type;
	this->projectType = projectType;
}

Block::Block(__int16 slices)
{
	this->slices = slices;
	update_type();
}

bool Block::isOverlap(__int16 slices)
{
	// 判断是否有重叠块，如果不重叠，则按位与运算后，全为0。取反后返回
	__int16 result = this->slices & slices;
	return !bool(result);
}

bool Block::equal(Block blk)
{
	if (this->slices == blk.slices)
		return true;
	else
		return false;
}

int Block::get_type()
{
	return type;
}

int Block::get_projectType()
{
	return projectType;
}

__int16 Block::get_slice()
{
	return slices;
}

__int16 Block::mk_slice(int type)
{
	return sliceMap[type];
}

__int16 Block::operator +(Block blk)
{
	// 计算组合后的块
	__int16 overlap = this->slices & blk.slices;
	this->slices = this->slices | blk.slices;
	update_type();
	if (type == -1)
		return overlap;
	else
		return sliceMap[0];
}

__int16 Block::operator -(Block blk)
{
	__int16 overlap = this->slices & blk.slices;
	this->slices = this->slices &( ~blk.slices);
	update_type();
	if (type == -1)
		return overlap;
	else
		return sliceMap[0];
}


bool Block::isOverlap(Block blk1, Block blk2)
{
	__int16 result = blk1.slices & blk2.slices;
	return !bool(result);
}

Block Block::combine(Block blk1, Block blk2)
{
	// 计算组合后的块
	__int16 result = blk1.slices | blk2.slices;
	Block newBlk = Block(result);
	return newBlk;
}
