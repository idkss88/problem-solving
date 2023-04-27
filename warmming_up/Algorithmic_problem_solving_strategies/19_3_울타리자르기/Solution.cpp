#include <vector>

vector<int> h;

int sovleStack() {
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	
	for(int i = 0 ; i < h.size() ; i++) {
		while(!remaining.empty() && h[remaining.top()] >= h[i] {
			int j = remainig.top();
			remaining.pop();
			int width = -1;
			
			if (remaing.empty()) {
				width =  i;

			} else {
				width = ( i -  remaining.top() - 1);
				ret = max(ret, h[j] * width);
			}
			remaiming.push(i);		
		}	
	}
	return ret;		
}
