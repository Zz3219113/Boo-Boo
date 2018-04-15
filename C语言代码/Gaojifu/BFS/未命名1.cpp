/**
 * 广度优先搜索
 * @param Vs 起点
 * @param Vd 终点
 */
bool BFS(Node& Vs, Node& Vd){
	queue<Node> Q;
	Node Vn, Vw;
	int i;

	//用于标记颜色当visit[i][j]==true时，说明节点访问过，也就是黑色
	bool visit[MAXL][MAXL];

	//四个方向
	int dir[][2] = {
		{0, 1}, {1, 0},
		{0, -1}, {-1, 0}
	};

	//初始状态将起点放进队列Q
	Q.push(Vs);
	visit[Vs.x][Vs.y] = true;//设置节点已经访问过了！

	while (!Q.empty()){//队列不为空，继续搜索！
		//取出队列的头Vn
		Vn = Q.front();
		Q.pop();

		for(i = 0; i < 4; ++i){
			Vw = Node(Vn.x+dir[i][0], Vn.y+dir[i][1]);//计算相邻节点

			if (Vw == Vd){//找到终点了！
				//把路径记录，这里没给出解法
				return true;//返回
			}

			if (isValid(Vw) && !visit[Vw.x][Vw.y]){
				//Vw是一个合法的节点并且为白色节点
				Q.push(Vw);//加入队列Q
				visit[Vw.x][Vw.y] = true;//设置节点颜色
			}
		}
	}
	return false;//无解
}
