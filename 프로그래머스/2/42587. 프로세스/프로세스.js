function solution(pr, location) {
    let answer = 0;
    while(pr.length !== 0){
        let temp = pr[0];
        if(Math.max(...pr) !== temp) {
            pr.splice(0,1);
            pr.push(temp);
            location -= 1;
            if(location < 0) location += pr.length;
        }

        else {
            console.log(temp);
            pr.splice(0,1);
            answer += 1;
            if(location === 0) break;
            location -= 1;
        }
    }
    return answer;
}