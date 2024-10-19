function solution(pr, location) {
    var answer = 0;
    while(pr.length !== 0){
        let poppedPr = pr[0];
        if(poppedPr === Math.max(...pr)){
            pr.splice(0,1);
            answer += 1;
            if(location === 0) break;
        }
        else{
            pr.splice(0,1);
            pr.push(poppedPr);
        }
        location -= 1;
        if(location < 0){
            location += pr.length;
        }
    }
    return answer;
}