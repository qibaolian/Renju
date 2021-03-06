#include"history_heuristic.h"
#include"define.h"

HistoryHeuristic::HistoryHeuristic()
{
	ResetHistoryTable();
}

HistoryHeuristic::~HistoryHeuristic()
{

}

void HistoryHeuristic::ResetHistoryTable()
{
	//初始化历史表
	for(int i=0;i<BOARD_NUM;i++)
		for (int j = 0; j < BOARD_NUM; j++)
		{
			History_Table[i][j] = 10;
		}
}


int HistoryHeuristic::GetHistoryScore(ChessMove move)
{
	return History_Table[move.ChessPos.y][move.ChessPos.x];//获取给定步骤历史表得分
}

void HistoryHeuristic::EnterHistoryScore(ChessMove move, int depth)
{
	History_Table[move.ChessPos.y][move.ChessPos.x] += 2 << depth;
}

void HistoryHeuristic::QSort(ChessMove *source, int low, int high)
{
	int i;
	if (low < high)
	{
		i = Partition(source, low, high);
		QSort(source, low, i - 1);
		QSort(source, i+1, high);
	}
}

int HistoryHeuristic::Partition(ChessMove *source, int low, int high)
{
	ChessMove temp;
	temp = source[low];
	int score = temp.Score;
	while (low < high)
	{
		while (source[high].Score <= score&&low < high)
			high--;
		source[low] = source[high];
		while (source[low].Score > score&&low < high)
			low++;
		source[high] = source[low];
	}
	source[low] = temp;
	return low;
}


