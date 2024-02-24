class StockSpanner {
public:
stack<int> stack;
vector<int> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!stack.empty() && price >= stock[stack.top()]){
            stack.pop();
        }
        int span = stack.empty()?stock.size()+1 : stock.size()-stack.top();
        stock.push_back(price);
        stack.push(stock.size()-1);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */