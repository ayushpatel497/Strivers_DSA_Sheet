class StockSpanner {
public:
    vector<pair<int, int>> stack;
    StockSpanner() {
        // Q. Online Stock Span
    }
    
    int next(int price) {
        int curPrice = price;
        int curSpan = 1;

        while(stack.size() && stack.back().first <= price ){
            pair<int, int> pp = stack.back();
            stack.pop_back();
            curSpan += pp.second;
        }
        stack.push_back({curPrice, curSpan});
        return curSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */