#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ÿ���ߴ��������
int edge[11][11]={  
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    
	{0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},    
	{0, 0, 0, 1, 3, 5, 0, 0, 0, 0, 0},    
	{0, 2, 1, 0, 0, 6, 8, 0, 0, 0, 0},    
	{0, 0, 3, 0, 0, 4, 0, 9, 11,0, 0},    
	{0, 0, 5, 6, 4, 0, 7, 0, 12,14,0},    
	{0, 0, 0, 8, 0, 7, 0, 0, 0, 15,17},    
	{0, 0, 0, 0, 9, 0, 0, 0, 10,0, 0},    
	{0, 0, 0, 0, 11,12,0, 10,0, 13, 0},    
	{0, 0, 0, 0, 0, 14,15,0, 13, 0, 16},    
	{0, 0, 0, 0, 0, 0, 17,0, 0, 16,0},    
};    
// ����ÿ����λ�����δ��������
int tri[9] = {7, 56, 98, 448, 3584, 6160, 28672, 49280, 229376};    
int end_state = (1<<18)-1; // �ս�״̬ 2^18 - 1 �������б߾������
int inf = (1<<20);

int next_state(int cur_state, int edge, int *cnt)
{
	int i;
	int new_state = (cur_state | edge); // ��ǰ���沢��һ�����γ��¾���
	for(i = 0; i < 9; i++) // ����¾������γ�һ���µĵ�λ�����Σ��� cnt++
		if(((cur_state & tri[i]) != tri[i]) && ((new_state & tri[i]) == tri[i]))
			(*cnt)++;
	return new_state;
}

int alpha_beta(int player, int cur_state, int alpha, int beta, int ca, int cb)
{
	int remain;
	// �� A �õ� 5 �������� A Ӯ
	// �� B �õ� 5 �������� A ��
	if(ca >= 5) return 1;
	if(cb >= 5) return -1;
	remain = ((~cur_state) & end_state); // ����ʣ����ߵı�
	if(player){ // A ��
		while(remain){ // �п��߱�
			int move = (remain & (-remain)); // ѡ��һ�����߱�
			int ta = ca;
			int val;
			// A ���˱ߺ��γ��µľ���
			int new_state = next_state(cur_state, move, &ta);
			if(ta > ca) // ��� A �÷��ˣ��� A ������һ����
				val = alpha_beta(player, new_state, alpha, beta, ta, cb);
			else // �����ֵ� B ��
				val = alpha_beta(player^1, new_state, alpha, beta, ca, cb);
			if(val > alpha)
				alpha = val;
			if(alpha >= beta) 
				return alpha;
			remain -= move; // �ѱ� move ��ʣ���ѡ�� remain ���Ƴ�
		}
		return alpha;
	}
	else{ // B ��
		while(remain){
			int move = (remain & (-remain));
			int tb = cb;
			int val;
			int new_state = next_state(cur_state, move, &tb);
			if(tb > cb)
				val = alpha_beta(player, new_state, alpha, beta, ca, tb);
			else
				val = alpha_beta(player^1, new_state, alpha, beta, ca, cb);
			if(val < beta)
				beta = val;
			if(alpha >= beta)
				return beta;
			remain -= move;
		}
		return beta;
	}
}

int main()
{
#if 0
	freopen("in.txt","r",stdin);
#endif
	int T, w = 0;
	scanf("%d", &T);
	while(T--){
		int i;
		int n;
		int ans;
		int cnt = 0; // ż���ֵ� A �ߣ������ֵ� B ��
		int cur_state = 0; // ��ǰ����
		int ca = 0; // A �ĵ÷�
		int cb = 0; // B �ĵ÷�
		int ta, tb;
		int alpha = -inf;
		int beta = inf;
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			int u, v;
			ta = ca;
			tb = cb;
			scanf("%d%d", &u, &v);
			cur_state = next_state(cur_state, 1<<edge[u][v], (cnt & 1) ? (&cb) : (&ca));
			if(ta == ca && tb == cb) // ���÷֣��ֵ��Է���
				cnt++;
		}
		if(cnt & 1) 
			ans = alpha_beta(0, cur_state, alpha, beta, ca, cb);
		else
			ans = alpha_beta(1, cur_state, alpha, beta, ca, cb);
		if(ans > 0)
			printf("Game %d: A wins.\n", ++w);
		else
			printf("Game %d: B wins.\n", ++w);
	}
	return 0;
}
