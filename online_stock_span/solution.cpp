/*
Algorithm Idea

when looking for the span of some stock's price, we can first consider the span of
the previously inserted price.

let 'price' be the price we seek the span of.

if 'price' is less than the previous day's stock price, then,
    the span is just one day.
else if 'price' is more than the previous day's stock price, then,
    add one to the span of the previous day's price
    AND
    while the cut-off price of previous days is less than today's price
        also add the span of the cut-off price.
        prevSpanInfo = c
    
        
*/

/*
spanDays = 1

if spanInfo not empty:
    prevSpanInfo = spanInfo.most_recent

    while prevSpanIno != nullptr && prevSpanInfo.price <= price:
        span += prevSpanInfo.spanDays
        prevSpanInfo = prevSpanInfo.cutOffSpanInfo



*/


// class StockSpanner {
// public:
//     struct SpanInfo{
//         SpanInfo* cutOffSpanInfo;
//         int price;
//         int spanDays;
//     };
    
//     SpanInfo* head;
//     StockSpanner() {
//         head = nullptr;
//     }
    
//     int next(int price) {
//         int spanDays = 1;
    
        
//         SpanInfo* prevSpanInfo = head;
//         while(prevSpanInfo != nullptr && prevSpanInfo->price <= price)
//         {
//             spanDays += prevSpanInfo->spanDays;
//             prevSpanInfo = prevSpanInfo->cutOffSpanInfo;
//         }

        
//         head = new SpanInfo{prevSpanInfo, price, spanDays};

//         return spanDays;
//     }
// };



#include <vector>
using namespace std;

class StockSpanner {
public:

    struct SpanInfo{
        int cutOffSpanInfoIndex;
        int price;
        int spanDays;

        SpanInfo() {
            cutOffSpanInfoIndex = price = spanDays = 0;
        }
        SpanInfo(int cutOff, int price, int spanDays): cutOffSpanInfoIndex{cutOff}, price{price}, spanDays{spanDays} {};

    };
    
    int headIndex;
    vector<SpanInfo> spanInfoVector;
    StockSpanner() {
        headIndex = -1;
        spanInfoVector = vector<SpanInfo>();
    }
    
    int next(int price) {
        int spanDays = 1;
        
        int prevSpanInfoIndex = headIndex;
        while(prevSpanInfoIndex != -1)
        {
            SpanInfo& prevSpanInfo = spanInfoVector[prevSpanInfoIndex];
            if(prevSpanInfo.price <= price)
            {
                spanDays += prevSpanInfo.spanDays;
                prevSpanInfoIndex = prevSpanInfo.cutOffSpanInfoIndex;
            }
            else
            {
                break;
            }
            
        }

        headIndex++;
        spanInfoVector.emplace_back(prevSpanInfoIndex, price, spanDays);

        return spanDays;
    }
};

    
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
