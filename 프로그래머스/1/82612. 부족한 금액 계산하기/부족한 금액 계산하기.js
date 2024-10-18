function solution(price, money, count) {
    let answer = 0;
    let cost = calculateCost(price,count);
    if(money < cost){
        answer = cost-money
    }
    
    return answer;
}

function calculateCost(price,count){
    let cost = 0;
    for(let i=1;i<=count;i++){
        cost += price * i
    }
    return cost;
}